#include "client_deposits_presenter.h"

#include <QDebug>


ClientDepositsPresenter::ClientDepositsPresenter(std::shared_ptr<IClient> client, QObject *parent) :
    client(client), clientDepositsView(std::make_shared<ClientDepositsView>(this)), QObject(parent)
{
    connect(clientDepositsView->getDepositInfoBtn(), SIGNAL(clicked()), this, SLOT(showDepositInfo()));
    connect(clientDepositsView->getOpenDepositBtn(), SIGNAL(clicked()), this, SLOT(openDeposit()));
    connect(clientDepositsView->getWithdrawMoneyBtn(), SIGNAL(clicked()), this, SLOT(withdrawMoney()));
    connect(this, SIGNAL(showDepositInfo(QString)), clientDepositsView.get(), SLOT(showDepositInfo(QString)));
    connect(this, SIGNAL(errorHappened(QString)), clientDepositsView.get(), SLOT(showError(QString)));
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
    emit showDepositInfo(client->getDeposit(clientDepositsView->getIdOfSelectedAccount()).getInfo());
}

void ClientDepositsPresenter::openDeposit()
{
    qDebug() << "Open deposit.\n";
    try
    {
        int term = clientDepositsView->getIntFromClinet("Срок вклада", "Введите срок вклада в месяцах(от 2 до 24)", 2, 2, 24, 1);
        double sum = clientDepositsView->getDoubleFromClient("Сумма вклада", "Введите сумму вклада (BYN 100 - 100000)", 100, 100, 100000, 2);
        client->openDeposit(term, sum);
        client->updateDepositQueryModel();
    }
    catch(const std::exception& ex)
    {
        emit errorHappened(QString(ex.what()));
    }
}

void ClientDepositsPresenter::withdrawMoney()
{
    qDebug() << "Withdraw money.\n";
}
