#include "client_accounts_view.h"
#include <QVBoxLayout>
#include <QDebug>

ClientAccountsView::ClientAccountsView(QWidget *parent) : QWidget(parent)
{
    initUi();
}

void ClientAccountsView::openAccount()
{
    qDebug() << "Open account.\n";
}

void ClientAccountsView::closeAccount()
{
    qDebug() << "Close account.\n";
}

void ClientAccountsView::showAccountInfo()
{
    qDebug() << "Show account info.\n";
}

void ClientAccountsView::putMoney()
{
    qDebug() << "Put money.\n";
}

void ClientAccountsView::withdrawMoney()
{
    qDebug() << "Withdraw money.\n";
}

void ClientAccountsView::transferMoney()
{
    qDebug() << "Transfer money.\n";
}

void ClientAccountsView::changeCurrentAccountId(QListWidgetItem *listItem)
{
    qDebug() << "Change current account id(Еще не знаю зачем это).\n";
}

void ClientAccountsView::initUi()
{
    setFixedWidth(500);
    setFixedHeight(500);

    setWindowTitle("Работа со счетами");

    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);

    // TODO: Разобрать что за accountsListWidget. И возможно перенести в объявление класса.
    auto accountsListWidget = new QListWidget(this);

    // Здесь нужно получать список счетов Клиента из базы данных
    // Отображать нужно только их id'шники
    //updateClientAccountsData();
    //updateClientAccountsListWidget();


    openAccountBtn = new QPushButton("Открыть новый счёт", this);
    connect(openAccountBtn, SIGNAL(clicked()), this, SLOT(openAccount()));

    closeAccountBtn = new QPushButton("Закрыть счёт", this);
    connect(closeAccountBtn, SIGNAL(clicked()), this, SLOT(closeAccount()));

    withdrawBtn = new QPushButton("Снять деньги", this);
    connect(withdrawBtn, SIGNAL(clicked()), this, SLOT(withdrawMoney()));

    transferBtn = new QPushButton("Перевести деньги", this);
    connect(transferBtn, SIGNAL(clicked()), this, SLOT(transferMoney()));

    putMoneyBtn = new QPushButton("Положить деньги", this);
    connect(putMoneyBtn, SIGNAL(clicked()), this, SLOT(putMoney()));

    showAccInfoBtn = new QPushButton("Информация о счёте", this);
    connect(showAccInfoBtn, SIGNAL(clicked()), this, SLOT(showAccountInfo()));

    vBoxLayout->addWidget(accountsListWidget);
    vBoxLayout->addWidget(showAccInfoBtn);
    vBoxLayout->addWidget(openAccountBtn);
    vBoxLayout->addWidget(closeAccountBtn);
    vBoxLayout->addWidget(withdrawBtn);
    vBoxLayout->addWidget(transferBtn);
    vBoxLayout->addWidget(putMoneyBtn);
    setLayout(vBoxLayout);
}
