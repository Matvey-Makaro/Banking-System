#include "bankSystem.h"
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


IBank& BankSystem::getBank(const QString& bankName)
{
    // Исправить, надо сначала поискать создавался ли такой банк, и если нет, то создавать новый
//    std::find(banks.begin(), banks.end(), [&bankName](std::shared_ptr<IBank> bank){
//       //return bank->getName() == bankName;
//        return true;
//    });
    banks.push_back(std::make_shared<Bank>(bankName));
    qDebug() << banks.back()->getName();
    return *banks.back();
}


void BankSystem::readBankNames()
{

    QString str = "SELECT * FROM " + bankNamesTableName + ";";
    if(!query.exec(str))
        qDebug() << "Can't make command: " + str << '\n';
    while(query.next())
        bankNames.push_back(query.value("name").toString());
}
