#include "mainPresenter.h"
#include "bankSystem.h"
#include "authorizationView.h"

#include <QString>
#include <QListWidget>
#include <QVariant>

// Могуть быть проблемы из-за такого списка инизиализации
MainPresenter::MainPresenter(QObject *parent) :
    bankSystem(std::make_shared<BankSystem>()),
    chooseBankView(std::make_shared<ChooseBankView>(bankSystem->getBankNames())),
    QObject(parent)
{
    chooseBankView->show();
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
    authorizationPresenter = std::make_shared<AuthorizationPresenter>(bank, this);
}
