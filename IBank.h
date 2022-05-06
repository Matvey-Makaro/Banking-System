#pragma once

#include "user.h"
#include "IClient.h"

#include <QString>



class IBank
{
public:
    virtual void addUserToApplicationsForRegistration(User& user) = 0;
    virtual User getUser(QString& login, QString& password) const = 0;
    virtual const QString& getName() const = 0;
    virtual ~IBank() = default;
};
