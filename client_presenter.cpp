#include "clientPresenter.h"

ClientPresenter::ClientPresenter(std::shared_ptr<IClient> client, QObject *parent) :
    client(client), clientView(std::make_shared<ClientView>(this)), QObject(parent)
{
    connect(clientView->getAccountsWorkBtn(), SIGNAL(clicked()), this, SLOT(goToClientAccounts()));
    connect(clientView->getDepositsWorkBtn(), SIGNAL(clicked()), this, SLOT(goToClientDeposits()));
    connect(clientView->getCreditsBtn(), SIGNAL(clicked()), this, SLOT(goToClientCredits()));
    connect(clientView->getInstallmentsBtn(), SIGNAL(clicked()), this, SLOT(goToClientInstallments()));
    connect(clientView->getSalaryProjectBtn(), SIGNAL(clicked()), this, SLOT(goToSalaryProject()));
    clientView->show();
}

void ClientPresenter::goToClientAccounts()
{
    qDebug() << "Show client accounts window.\n";
}

void ClientPresenter::goToClientDeposits()
{
    qDebug() << "Show client deposits window.\n";
}

void ClientPresenter::goToClientCredits()
{
    qDebug() << "Show client credits window.\n";
}

void ClientPresenter::goToClientInstallments()
{
    qDebug() << "Show client installments window\n";
}

void ClientPresenter::goToSalaryProject()
{
    qDebug() << "Show salary project window.\n";
}
