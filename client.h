#pragma once

#include "IClient.h"
#include "IBank.h"

#include <QString>
#include <memory>

class Client : public IClient
{
public:
    Client(int id, QString name, QString surname, QString patronymic, QString phoneNumber, QString email, QString passport, bool fromRB, std::shared_ptr<IBank> bank);
    virtual int getId() const override { return id; }
    virtual const QString& getName() const override { return name; }
    virtual const QString& getSurname() const override { return surname; }
    virtual const QString& getPatronymic() const override { return patronymic; }
    virtual const QString& getPhoneNumber() const override { return phoneNumber; }
    virtual const QString& getEmail() const override { return email; }
    virtual const QString& getPassport() const override { return passport; }
    virtual bool isFromRB() const override { return fromRB; }

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
    std::shared_ptr<IBank> currentBank;
};

