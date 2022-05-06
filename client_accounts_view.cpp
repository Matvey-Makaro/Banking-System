#include "client_accounts_view.h"
#include <QVBoxLayout>
#include <QDebug>

ClientAccountsView::ClientAccountsView(QWidget *parent) : QWidget(parent)
{
    initUi();
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
    closeAccountBtn = new QPushButton("Закрыть счёт", this);
    withdrawBtn = new QPushButton("Снять деньги", this);
    transferBtn = new QPushButton("Перевести деньги", this);
    putMoneyBtn = new QPushButton("Положить деньги", this);
    showAccInfoBtn = new QPushButton("Информация о счёте", this);


    vBoxLayout->addWidget(accountsListWidget);
    vBoxLayout->addWidget(showAccInfoBtn);
    vBoxLayout->addWidget(openAccountBtn);
    vBoxLayout->addWidget(closeAccountBtn);
    vBoxLayout->addWidget(withdrawBtn);
    vBoxLayout->addWidget(transferBtn);
    vBoxLayout->addWidget(putMoneyBtn);
    setLayout(vBoxLayout);
}
