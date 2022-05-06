#pragma once

#include <QString>

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


    virtual ~IClient() = default;
};
