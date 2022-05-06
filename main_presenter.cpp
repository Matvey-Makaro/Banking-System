#include "main_presenter.h"
#include "bank_system.h"
#include "authorization_view.h"

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
    connect(chooseBankView->getBanksNameListWidget(), SIGNAL(itemDoubleClicked(QListWidgetItem*)),
            this, SLOT(goToAuthorization(QListWidgetItem*)));
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
    chooseBankView->hide();
}
