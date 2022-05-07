#pragma once

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


    virtual ~IClient() = default;
};
