#pragma once

#include "IBank.h"
#include "userType.h"

#include <cstdint>
#include <QString>



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
    //Bank& currentBank;
};

