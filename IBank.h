#pragma once

#include "userType.h"

#include <QString>


class IBank
{
public:
    virtual void createUser(const QString& login, const QString& password, const UserType type,
                            const QString& name, const QString& surname, const QString& patronymic,
                            const QString& phoneNumber, const QString& email) = 0;

    virtual ~IBank() = default;
};
