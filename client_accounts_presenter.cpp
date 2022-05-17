#include "client_accounts_presenter.h"

ClientAccountsPresenter::ClientAccountsPresenter(std::shared_ptr<IClient> client, QObject *parent) :
    client(client) ,clientAccountsView(std::make_shared<ClientAccountsView>(this)) , QObject(parent)
{
    connect(clientAccountsView->getOpenAccountBtn(), SIGNAL(clicked()), this, SLOT(openAccount()));
    connect(clientAccountsView->getCloseAccountBtn(), SIGNAL(clicked()), this, SLOT(closeAccount()));
    connect(clientAccountsView->getWithdrawBtn(), SIGNAL(clicked()), this, SLOT(withdrawMoney()));
    connect(clientAccountsView->getTransferBtn(), SIGNAL(clicked()), this, SLOT(transferMoney()));
    connect(clientAccountsView->getPutMoneyBtn(), SIGNAL(clicked()), this, SLOT(putMoney()));
    connect(clientAccountsView->getShowAccInfoBtn(), SIGNAL(clicked()), this, SLOT(showAccountInfo()));
    connect(this, SIGNAL(showAccountInfo(QString)), clientAccountsView.get(), SLOT(showAccountInfo(QString)));
    clientAccountsView->show();
}

QSqlQueryModel &ClientAccountsPresenter::getAccountsQueryModel() const
{
    return client->getAccountQueryModel();
}

void ClientAccountsPresenter::openAccount()
{
    qDebug() << "Open account.\n";
    client->openAccount();
    client->updateAccountQueryModel();
}

void ClientAccountsPresenter::closeAccount()
{
    qDebug() << "Close account.\n";
    client->closeAccount(clientAccountsView->getIdOfSelectedAccount());
    client->updateAccountQueryModel();

}

void ClientAccountsPresenter::showAccountInfo()
{
    qDebug() << "Show account info.\n";
    emit showAccountInfo(client->getAccount(clientAccountsView->getIdOfSelectedAccount()).getInfo());
}

void ClientAccountsPresenter::putMoney()
{
    qDebug() << "Put money.\n";
    //double sum = clientAccountsView->getPutMoneyFromClient();
    double sum = clientAccountsView->getDoubleFromClient("Положить деньги", "Введите сумму пополнения", 0, 0, 10000, 2);
    client->putMoneyOnAccount(clientAccountsView->getIdOfSelectedAccount(), sum);
}

void ClientAccountsPresenter::withdrawMoney()
{
    qDebug() << "Withdraw money.\n";
    //double sum = clientAccountsView->getWithdrawMoneyFromClient();
    double sum = clientAccountsView->getDoubleFromClient("Снять деньги", "Введите сумму, которую хотите снять", 0, 0, 10000, 2);
    client->withdrawMoneyFromAccount(clientAccountsView->getIdOfSelectedAccount(), sum);
}

void ClientAccountsPresenter::transferMoney()
{
    qDebug() << "Transfer money.\n";
    int dstAccountId = clientAccountsView->getIntFromClinet("Перевод средств", "Введите номер счёта", 0, 0, 2147483647, 1);
    if(dstAccountId >= 0)
    {
        double sum = clientAccountsView->getDoubleFromClient("Перевод средств", "Введите сумму, которую хотите перевести", 0, 0, 10000, 2);
        int srcAccountId = clientAccountsView->getIdOfSelectedAccount();
        client->transferMoney(srcAccountId, dstAccountId, sum);
    }
}

void ClientAccountsPresenter::changeCurrentAccountId(QListWidgetItem *listItem)
{
    qDebug() << "Change current account id(Еще не знаю зачем это).\n";
}
