#pragma once

#include "user.h"
#include "account.h"

#include <QString>
#include <QSqlQueryModel>



class IBank
{
public:
    virtual void addUserToApplicationsForRegistration(User& user) = 0;
    virtual User getUser(QString& login, QString& password) const = 0;
    virtual QSqlQueryModel& getClientAccountsModel(int clientId) = 0;
    virtual void createAccoutForClient(int clientId) = 0;
    virtual void updateClientAccountsModel() = 0;
    virtual void closeClientAccount(int accountId) const = 0;
    virtual Account getClientAccount(int accountId) const = 0;
    virtual void putMoneyOnClientAccount(int accountId, double sum) = 0;
    virtual void withdrawMoneyFromClientAccout(int accoutId, double sum) = 0;
    virtual void transferMoney(int srcAccountId, int dstAccountId, double sum) = 0;
    virtual const QString& getName() const = 0;
    virtual ~IBank() = default;
};
