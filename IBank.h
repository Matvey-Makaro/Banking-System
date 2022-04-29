#pragma once

#include "user.h"

#include <QString>



class IBank
{
public:
    virtual void addUserToApplicationsForRegistration(User& user) = 0;
    virtual void addUserToApplicationsForRegistration(const QString& login, const QString& password, const UserType type,
                            const QString& name, const QString& surname, const QString& patronymic,
                            const QString& phoneNumber, const QString& email) = 0;
    virtual const QString& getName() const = 0;
    virtual ~IBank() = default;
};
