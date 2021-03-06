#include <iostream>
#include <sstream>

#include <QPushButton>
#include <QGridLayout>
#include <QListWidget>
#include <QMessageBox>
#include <QInputDialog>

#include "clientdepositswindow.h"
#include "ibanksystemmodel.h"
#include "deposit.h"
#include "constants.h"

ClientDepositsWindow::ClientDepositsWindow(IBankSystemModel *bankSystem, Client *cl)
    : bankSystemModel(bankSystem), client(cl)
{
    setFixedWidth(500);
    setFixedHeight(500);

    setWindowTitle("Работа со вкладами");

    /*
     * a. Создание
     * b. Закрытие (как только истёк срок вклада, но НЕ РАНЬШЕ)
     * e. Накопление
     * */

    QGridLayout *gridLayout = new QGridLayout(this);

    depositsListWidget = new QListWidget(this);

    // Здесь нужно получать список вкладов Клиента из базы данных
    // Отображать нужно только их id'шники
    updateClientDepositsData();
    updateClientDepositsListWidget();

    QPushButton *depositInfo = new QPushButton("Информация о вкладе", this);
    connect(depositInfo, &QPushButton::clicked, this, &ClientDepositsWindow::showDepositInfo);

    QPushButton *openDeposit = new QPushButton("Открыть новый вклад", this);
    connect(openDeposit, &QPushButton::clicked, this, &ClientDepositsWindow::openDeposit);

    QPushButton *withdrawMoney = new QPushButton("Вывести деньги", this);
    connect(withdrawMoney, &QPushButton::clicked, this, &ClientDepositsWindow::withdrawMoney);

    gridLayout->addWidget(depositsListWidget, 0, 0);
    gridLayout->addWidget(depositInfo, 1, 0);
    gridLayout->addWidget(openDeposit, 2, 0);
    gridLayout->addWidget(withdrawMoney, 3, 0);
}

ClientDepositsWindow::~ClientDepositsWindow()
{
    deleteClientDepositsData();
}

void ClientDepositsWindow::deleteClientDepositsData()
{
    for (Deposit *d : clientDeposits)
    {
        delete d;
    }
}

int64_t ClientDepositsWindow::getCurrentDepositId()
{
    QList<QListWidgetItem*> selected = depositsListWidget->selectedItems();

    if (selected.size() != 1)
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Вы должны выбрать один из вкладов");
        msgBox.exec();
        return -1;
    }

    int64_t depId = selected[0]->text().toInt();
    return depId;
}

void ClientDepositsWindow::updateClientDepositsData()
{
    deleteClientDepositsData();

    std::list<Deposit *> deposits = bankSystemModel->getClientDeposits(client);
    clientDeposits = deposits;

    for (Deposit *d : deposits)
    {
        int status = d->getStatus();

        if (status != ACTIVE && status != CLOSED && status != FROZEN)
        {
            delete d;
            clientDeposits.remove(d);
        }
    }

    for (Deposit *d : clientDeposits)
    {
        std::cout << d->getId() << ": " << d->getStatus() << "\n";
    }
}

void ClientDepositsWindow::updateClientDepositsListWidget()
{
    depositsListWidget->clear();

    int i = 0;
    for (Deposit *d : clientDeposits)
    {
        depositsListWidget->insertItem(i, std::to_string(d->getId()).c_str());
    }
}

void ClientDepositsWindow::showDepositInfo()
{
    int64_t depId = getCurrentDepositId();
    if (depId == -1) { return; }

    bankSystemModel->clientDepositAccumulate(depId);
    bankSystemModel->clientDepositCheckTerm(depId);

    updateClientDepositsData();
    auto it = std::find_if(std::begin(clientDeposits),
                           std::end(clientDeposits),
                           [&](const Deposit *dep){ return dep->getId() == depId; } );

    Deposit *currDep = *it;

    QMessageBox msgBox;
    msgBox.setWindowTitle("Информация о вкладе");

    std::string info = currDep->getInfo();

    msgBox.setText(info.c_str());
    msgBox.exec();
}

void ClientDepositsWindow::openDeposit()
{
    // Нужно запросить у Клиента:
    // - Срок вклада в месяцах
    // - Сумму вклада
    QInputDialog inpDialog;
    bool ok;

    unsigned term = 0;
    do
    {
        std::stringstream ss;
        ss << "Введите срок вклада (в месяцах, от " << MIN_DEPOSIT_TERM << " до " << MAX_DEPOSIT_TERM << ")";
        term = inpDialog.getInt(this, "Срок вклада", ss.str().c_str(), 3, MIN_DEPOSIT_TERM, MAX_DEPOSIT_TERM, 1, &ok);
    }
    while (!ok);

    double sum = 0;
    do
    {
        double maxValueUsd = 1000.0;
        CurrencyType currencyType = client->isFromRB() ? BYN : US_DOLLAR;
        QString currencyStr = client->isFromRB() ? "BYN" : "$";
        QString prompt = "Сумма вклада (" + currencyStr + ", 1.0 - " +
                QString::number(CurrencyConverter().convert(maxValueUsd, US_DOLLAR, currencyType)) + ")";
        sum = inpDialog.getDouble(this, "Сумма вклада", prompt, 1.0, 1.0, maxValueUsd, 2, &ok);
    }
    while (!ok);

    bankSystemModel->openDepositForClient(client, term, sum);

    updateClientDepositsData();
    updateClientDepositsListWidget();
}

void ClientDepositsWindow::withdrawMoney()
{
    int64_t id = getCurrentDepositId();
    Deposit *dep = bankSystemModel->getDepositById(id);
    int status = dep->getStatus();

    if (status == CLOSED)
    {
        double maxValue = dep->getBalance();

        QInputDialog inpDialog;
        bool ok;
        double withdrawValue;

        do
        {
            QString currency = dep->getCurrencyType() == BYN ? "BYN" : "$";
            QString prompt = "Введите сумму для снятия (" + currency + ")";

            withdrawValue = inpDialog.getDouble(this, "Сумма снятия", prompt, 1, 0, maxValue, 10, &ok);
        }
        while (!ok);

        dep->withdrawMoney(withdrawValue);
        bankSystemModel->updateDepositData(dep);

        updateClientDepositsData();
        updateClientDepositsListWidget();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Невозможно снять деньги");
        msgBox.setText("Вклад должен быть закрыт для того, чтобы можно было снять деньги.");
        msgBox.exec();
    }

    delete dep;
}
