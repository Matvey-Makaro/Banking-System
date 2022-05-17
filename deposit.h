#pragma once

#include "currency_type.h"

#include <QString>

enum DepositStatus
{
    OPEN,
    CLOSE
};

class Deposit
{
public:
    Deposit(int id, int clientId, double balance, double percent, time_t creationDate,
            unsigned term, CurrencyType currencyType, DepositStatus statusType);

    int getId() const { return id;}
    int getClientId() const {return clientId; }

    double getBalance() const { return balance; }
    void setBalance(double value) { balance = value; }

    double getPercent() const { return percent; }
    void setPercent(double value) { percent = value; }


    double getCreationDate() const { return creationDate; }

    CurrencyType getCurrencyType() const { return currencyType; }
    void setCurrencyType(const CurrencyType value) { currencyType = value; }

    DepositStatus getStatusType() const { return status; }
    void setStatusType(const DepositStatus value) { status = value; }

    QString getInfo() const;
    QString getClientName() const { return clientName; }
    void setClientName(const QString &value) { clientName = value; }

    unsigned getTerm() const { return term; }
    time_t getLastAccrualOfInterestTime() const { return lastAccrualOfInterestTime; }

//    void accumulate();
//    void checkTerm();
//    void withdrawMoney(double value);

protected:
    int id;
    int clientId;
    double balance;
    double percent;
    time_t creationDate;
    unsigned term;
    CurrencyType currencyType;
    DepositStatus status;
    QString clientName;
    time_t lastAccrualOfInterestTime;
};

