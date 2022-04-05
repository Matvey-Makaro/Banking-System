#pragma once

#include "IBank.h"

#include <cstdint>
#include <QString>


enum UserType
{
    CLIENT,
    ENTERPRISE_SPECIALIST,
    OPERATOR,
    MANAGER,
    ADMINISTRATOR,
    UNKNOWN
};


class User
{
public:
    User();


protected:
    UserType type;
    uint64_t id;
    QString login;
    QString password;
    QString name;
    QString surname;
    QString patronymic;
    QString phoneNumber;
    QString email;
    IBank& currentBank;
};

