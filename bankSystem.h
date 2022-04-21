#pragma once

#include "IBankSystem.h"
#include "IBank.h"

#include <QString>
#include <QStringList>
#include <QSqlQuery>
#include <QVector>
#include <memory>
#include <vector>

class BankSystem : public IBankSystem
{
public:
    BankSystem();
    virtual const QStringList& getBankNames() const override;
    virtual IBank& getBank(const QString& bankName) override;
    virtual ~BankSystem() {}

private:
    void readBankNames();

private:
    QVector<std::shared_ptr<IBank>> banks;
    //std::vector<std::shared_ptr<IBank>> banks;
    QStringList bankNames;
    QSqlQuery query;
    QVector<std::shared_ptr<IBank>> vec;
};

