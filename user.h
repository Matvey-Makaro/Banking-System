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
         QString phoneNumber, QString email, QString passport, bool isFromRB);
    UserType getType() const;
    const QString& getLogin() const;
    const QString& getPassword() const;
    const QString& getName() const;
    const QString& getSurname() const;
    const QString& getPatronymic() const;
    const QString& getPhoneNumber() const;
    const QString& getEmail() const;
    const QString& getPassport() const;
    bool getIsFromRB() const;
    // TODO: удалить или изменить, можно взять значение, до его установления, и возможно она вообще не нужна
    const QString& getEnterprise() const;
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
    QString passport;
    bool isFromRB;
    int id;
    int enterpriseId;
    QString hashedPassword;
    std::shared_ptr<IBank> currentBank;
    QString enterprise;
};

