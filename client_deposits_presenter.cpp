#include "client_deposits_presenter.h"

#include <QDebug>


ClientDepositsPresenter::ClientDepositsPresenter(std::shared_ptr<IClient> client, QObject *parent) :
    client(client), clientDepositsView(std::make_shared<ClientDepositsView>(this)), QObject(parent)
{
    connect(clientDepositsView->getDepositInfoBtn(), SIGNAL(clicked()), this, SLOT(showDepositInfo()));
    connect(clientDepositsView->getOpenDepositBtn(), SIGNAL(clicked()), this, SLOT(openDeposit()));
    connect(clientDepositsView->getWithdrawMoneyBtn(), SIGNAL(clicked()), this, SLOT(withdrawMoney()));
    clientDepositsView->show();
}

QSqlQueryModel &ClientDepositsPresenter::getDepositsQueryModel() const
{
    try
    {
        return client->getDepositQueryModel();
    }
    catch(const std::exception& ex)
    {
        emit errorHappened(QString(ex.what()));
    }
}

void ClientDepositsPresenter::showDepositInfo()
{
    qDebug() << "Show deposit info.\n";
}

void ClientDepositsPresenter::openDeposit()
{
    qDebug() << "Open deposit.\n";
}

void ClientDepositsPresenter::withdrawMoney()
{
    qDebug() << "Withdraw money.\n";
}
