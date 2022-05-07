#pragma once

#include "currency_type.h"
#include "account_status_type.h"

#include <QString>

class Account
{
public:
    Account(int id, int clientId, double balance, double percent, time_t creationDate, CurrencyType currencyType, AccountStatusType statusType);

    int getId() const;

    int getClientId() const;

    double getBalance() const;
    void setBalance(double value);

    double getPercent() const;
    void setPercent(double value);


    double getCreationDate() const;

    CurrencyType getCurrencyType() const;
    void setCurrencyType(const CurrencyType &value);

    AccountStatusType getStatusType() const;
    void setStatusType(const AccountStatusType &value);

    QString getInfo() const;
    QString getClientName() const;
    void setClientName(const QString &value);

private:
    int id;
    int clientId;
    double balance;
    double percent;
    time_t creationDate;
    CurrencyType currencyType;
    AccountStatusType statusType;
    QString clientName;
};

