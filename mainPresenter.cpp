#include "mainPresenter.h"
#include "bankSystem.h"
#include "authorizationView.h"

#include <QString>
#include <QListWidget>
#include <QVariant>

// Могуть быть проблемы из-за такого списка инизиализации
MainPresenter::MainPresenter(QObject *parent) :
    bankSystem(new BankSystem()), chooseBankView(new ChooseBankView(bankSystem->getBankNames())), QObject(parent)
{
    chooseBankView->show();
}

MainPresenter::~MainPresenter()
{
    if(bankSystem != nullptr)
        delete bankSystem;
    if(chooseBankView != nullptr)
        delete chooseBankView;
    // Добавить сюда другие сущности, которые будут созданы с помощью new

}

void MainPresenter::goToAuthorization(QListWidgetItem* chosenBank)
{
    getBankName(chosenBank);
    getBank();

    passContorlToAuthorizationPresenter();
}

void MainPresenter::getBank()
{
    bank = bankSystem->getBank(bankName);
}

void MainPresenter::getBankName(QListWidgetItem* item)
{
    bankName = item->data(Qt::DisplayRole).toString();

}

void MainPresenter::passContorlToAuthorizationPresenter()
{
    authorizationPresenter = new AuthorizationPresenter(bank, this);

}
