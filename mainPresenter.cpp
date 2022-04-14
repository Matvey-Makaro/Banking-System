#include "mainPresenter.h"

#include "bankSystem.h"

MainPresenter::MainPresenter(QObject *parent) : QObject(parent)
{
    bankSystem = new BankSystem();
    chooseBankView = new ChooseBankView(bankSystem->getBankNames());
    chooseBankView->show();
}
