#include "client_accounts_view.h"
#include "client_accounts_presenter.h"

#include <QVBoxLayout>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>

ClientAccountsView::ClientAccountsView(ClientAccountsPresenter* presenter, QWidget *parent) :
    clientAccountsPresenter(presenter), QWidget(parent)
{
    initUi();
}

double ClientAccountsView::getPutMoneyFromClient()
{
    QInputDialog inpDialog;
    bool ok;
    double inpMoney;
//    do
//    {
//        QString text = "Введите сумму пополнения";
//        inpMoney = inpDialog.getDouble(this, "Положить деньги", text,
//                                       0.0,
//                                       0.0,
//                                       1000,
//                                       2,
//                                       &ok);
//    }
//    while (!ok);
    QString text = "Введите сумму пополнения";
    inpMoney = inpDialog.getDouble(this, "Положить деньги", text,
                                   0.0,
                                   0.0,
                                   1000,
                                   2,
                                   &ok);
    if(ok)
        return inpMoney;
    else return 0.0;
}

void ClientAccountsView::showAccountInfo(QString accountInfo)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Информация о счёте");
    msgBox.setText(accountInfo);
    msgBox.exec();
}


void ClientAccountsView::initUi()
{
    setFixedWidth(500);
    setFixedHeight(500);

    setWindowTitle("Работа со счетами");

    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);

    // TODO: Разобрать что за accountsListWidget. И возможно перенести в объявление класса.
    // auto accountsListWidget = new QListWidget(this);
    accountsTableView = new QTableView(this);

    accountsTableView->setModel(&clientAccountsPresenter->getAccountsQueryModel());

    // Здесь нужно получать список счетов Клиента из базы данных
    // Отображать нужно только их id'шники
    //updateClientAccountsData();
    //updateClientAccountsListWidget();


    openAccountBtn = new QPushButton("Открыть новый счёт", this);
    closeAccountBtn = new QPushButton("Закрыть счёт", this);
    withdrawBtn = new QPushButton("Снять деньги", this);
    transferBtn = new QPushButton("Перевести деньги", this);
    putMoneyBtn = new QPushButton("Положить деньги", this);
    showAccInfoBtn = new QPushButton("Информация о счёте", this);


    vBoxLayout->addWidget(accountsTableView);
    vBoxLayout->addWidget(showAccInfoBtn);
    vBoxLayout->addWidget(openAccountBtn);
    vBoxLayout->addWidget(closeAccountBtn);
    vBoxLayout->addWidget(withdrawBtn);
    vBoxLayout->addWidget(transferBtn);
    vBoxLayout->addWidget(putMoneyBtn);
    setLayout(vBoxLayout);
}
