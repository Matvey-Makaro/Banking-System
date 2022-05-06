#include "bank_system.h"
#include "config.h"
#include "bank.h"

#include <QString>
#include <QVariant>
#include <QDebug>
#include <algorithm>

BankSystem::BankSystem()
{
    readBankNames();
}


const QStringList& BankSystem::getBankNames() const { return bankNames; }


std::shared_ptr<IBank> BankSystem::getBank(const QString& bankName)
{
    // Исправить, надо сначала поискать создавался ли такой банк, и если нет, то создавать новый
//    std::find(banks.begin(), banks.end(), [&bankName](std::shared_ptr<IBank> bank){
//       //return bank->getName() == bankName;
//        return true;
//    });
    std::shared_ptr<Bank> bank = std::make_shared<Bank>(bankName);
    banks.push_back(bank);
    qDebug() << banks.back()->getName();
    return bank;
}


void BankSystem::readBankNames()
{

    QString str = "SELECT * FROM " + bankNamesTableName + ";";
    if(!query.exec(str))
        qDebug() << "Can't make command: " + str << '\n';
    while(query.next())
        bankNames.push_back(query.value("name").toString());
}
