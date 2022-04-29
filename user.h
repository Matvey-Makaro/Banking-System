#pragma once

#include "userType.h"

#include <cstdint>
#include <QString>
#include <memory>

class IBank;


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
    int getEnterpriseId() const;
    void setEnterpriseId(int id);
    const QString& getHashedPassword() const;
    void setHashedPassword(QString password);
    std::shared_ptr<IBank> getCurrentBank() const;
    void setCurrentBank(std::shared_ptr<IBank> bank);



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
    int id;
    int enterpriseId;
    QString hashedPassword;
    std::shared_ptr<IBank> currentBank;
};

