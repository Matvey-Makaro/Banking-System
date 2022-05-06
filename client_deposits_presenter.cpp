#include "client_deposits_presenter.h"

#include <QDebug>

ClientDepositsPresenter::ClientDepositsPresenter(QObject *parent) :
    clientDepositsView(std::make_shared<ClientDepositsView>()), QObject(parent)
{
    connect(clientDepositsView->getDepositInfoBtn(), SIGNAL(clicked()), this, SLOT(showDepositInfo()));
    connect(clientDepositsView->getOpenDepositBtn(), SIGNAL(clicked()), this, SLOT(openDeposit()));
    connect(clientDepositsView->getWithdrawMoneyBtn(), SIGNAL(clicked()), this, SLOT(withdrawMoney()));
    clientDepositsView->show();
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
