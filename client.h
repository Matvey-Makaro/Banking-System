#pragma once

#include "IClient.h"

#include <QString>

class Client : public IClient
{
public:
    Client(int id, QString name, QString surname, QString patronymic, QString phoneNumber, QString email, QString passport, bool fromRB);


    virtual ~Client() = default;

private:
    int id;
    QString name;
    QString surname;
    QString patronymic;
    QString phoneNumber;
    QString email;
    QString passport;
    bool fromRB;
};

