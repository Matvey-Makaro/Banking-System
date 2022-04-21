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
    virtual std::shared_ptr<IBank> getBank(const QString& bankName) override;
    virtual ~BankSystem() = default;

private:
    void readBankNames();

private:
    QVector<std::shared_ptr<IBank>> banks;
    //std::vector<std::shared_ptr<IBank>> banks;
    QStringList bankNames;
    QSqlQuery query;
};

