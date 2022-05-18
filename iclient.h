#pragma once

#include "account.h"
#include "deposit.h"

#include <QString>
#include <QSqlQueryModel>

class IClient
{
public:
    virtual int getId() const = 0;
    virtual const QString& getName() const = 0;
    virtual const QString& getSurname() const = 0;
    virtual const QString& getPatronymic() const = 0;
    virtual const QString& getPhoneNumber() const = 0;
    virtual const QString& getEmail() const = 0;
    virtual const QString& getPassport() const = 0;
    virtual bool isFromRB() const = 0;
    virtual QSqlQueryModel& getAccountQueryModel() const = 0;
    virtual void updateAccountQueryModel() const = 0;
    virtual void openAccount() = 0;
    virtual void closeAccount(int accountId) = 0;
    virtual Account getAccount(int accountId) = 0;
    virtual void putMoneyOnAccount(int accountId, double sum) = 0;
    virtual void withdrawMoneyFromAccount(int accountId, double sum) = 0;
    virtual void transferMoney(int srcAccountId, int dstAccountId, double sum) = 0;
    virtual void openDeposit(int term, double sum) = 0;
    virtual QSqlQueryModel& getDepositQueryModel() const = 0;
    virtual void updateDepositQueryModel() const = 0;
    virtual Deposit getDeposit(int depositId) = 0;

    virtual ~IClient() = default;
};
