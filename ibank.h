#pragma once

#include "user.h"

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
    virtual const QString& getName() const = 0;
    virtual ~IBank() = default;
};
