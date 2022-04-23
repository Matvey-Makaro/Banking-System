#pragma once

#include "IBank.h"
#include "userType.h"

#include <cstdint>
#include <QString>



class User
{
public:
    User(QString login, QString password, QString name, QString surname, QString patronymic,
         QString phoneNumber, QString email, QString placeOfWork);
    UserType getType() const;
    const QString& getLogin() const;
    const QString& getPassword() const;
    const QString& getName() const;
    const QString& getSurname() const;
    const QString& getPatronymic() const;
    const QString& getPhoneNumber() const;
    const QString& getEmail() const;
    const QString& getPlaceOfWork() const;
    const QString& getHashedPassword() const;
    void setHashedPassword(QString password);



protected:
    UserType type;
    QString login;
    QString password;
    QString name;
    QString surname;
    QString patronymic;
    QString phoneNumber;
    QString email;
    QString placeOfWork;
    uint64_t id;
    QString hashedPassword;
    //Bank& currentBank;
};

