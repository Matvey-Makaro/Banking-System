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
    connect(this, SIGNAL(errorHappened(QString)), clientAccountsView.get(), SLOT(showError(QString)));
    clientAccountsView->show();
}

QSqlQueryModel &ClientAccountsPresenter::getAccountsQueryModel() const
{
    try
    {
        return client->getAccountQueryModel();
    }
    catch(const std::exception& ex)
    {
        emit errorHappened(QString(ex.what()));
    }
}

void ClientAccountsPresenter::openAccount()
{
    qDebug() << "Open account.\n";
    try
    {
        client->openAccount();
        client->updateAccountQueryModel();
    }
    catch(const std::exception& ex)
    {
        emit errorHappened(ex.what());
    }
}

void ClientAccountsPresenter::closeAccount()
{
    qDebug() << "Close account.\n";
    try
    {
        client->closeAccount(clientAccountsView->getIdOfSelectedAccount());
        client->updateAccountQueryModel();
    }
    catch(const std::exception& ex)
    {
        emit errorHappened(ex.what());
    }
}

void ClientAccountsPresenter::showAccountInfo()
{
    qDebug() << "Show account info.\n";
    emit showAccountInfo(client->getAccount(clientAccountsView->getIdOfSelectedAccount()).getInfo());
}

void ClientAccountsPresenter::putMoney()
{
    qDebug() << "Put money.\n";
    try
    {
        //double sum = clientAccountsView->getPutMoneyFromClient();
        double sum = clientAccountsView->getDoubleFromClient("Положить деньги", "Введите сумму пополнения", 0, 0, 10000, 2);
        client->putMoneyOnAccount(clientAccountsView->getIdOfSelectedAccount(), sum);
    }
    catch(const std::exception& ex)
    {
        emit errorHappened(ex.what());
    }
}

void ClientAccountsPresenter::withdrawMoney()
{
    qDebug() << "Withdraw money.\n";
    try
    {
        //double sum = clientAccountsView->getWithdrawMoneyFromClient();
        double sum = clientAccountsView->getDoubleFromClient("Снять деньги", "Введите сумму, которую хотите снять", 0, 0, 10000, 2);
        client->withdrawMoneyFromAccount(clientAccountsView->getIdOfSelectedAccount(), sum);
    }
    catch(const std::exception& ex)
    {
        emit errorHappened(ex.what());
    }
}

void ClientAccountsPresenter::transferMoney()
{
    qDebug() << "Transfer money.\n";
    try
    {
        int dstAccountId = clientAccountsView->getIntFromClinet("Перевод средств", "Введите номер счёта", 0, 0, 2147483647, 1);
        if(dstAccountId >= 0)
        {
            double sum = clientAccountsView->getDoubleFromClient("Перевод средств", "Введите сумму, которую хотите перевести", 0, 0, 10000, 2);
            int srcAccountId = clientAccountsView->getIdOfSelectedAccount();
            client->transferMoney(srcAccountId, dstAccountId, sum);
        }
    }
    catch(const std::exception& ex)
    {
        emit errorHappened(ex.what());
    }
}

