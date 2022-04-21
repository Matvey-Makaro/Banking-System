#include "mainPresenter.h"
#include "bankSystem.h"

#include <QString>
#include <QListWidget>
#include <QVariant>


MainPresenter::MainPresenter(QObject *parent) : QObject(parent)
{
    bankSystem = new BankSystem();
    chooseBankView = new ChooseBankView(bankSystem->getBankNames());
    chooseBankView->show();
}

void MainPresenter::getBankNameFromBankingSystem(QListWidgetItem* item)
{
    QString bankName = item->data(Qt::DisplayRole).toString();

}
