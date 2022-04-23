#pragma once

#include "IBank.h"
#include "userType.h"
#include "user.h"
#include "IPasswordHasher.h"

#include <QString>
#include <QStringList>
#include <QSqlQuery>
#include <memory>

class Bank : public IBank
{
public:
    Bank(QString bankName);
    virtual void createUser(User& user);
    virtual void createUser(const QString& login, const QString& password, const UserType type,
                            const QString& name, const QString& surname, const QString& patronymic,
                            const QString& phoneNumber, const QString& email);
    virtual const QString& getName() const override;
    virtual ~Bank() = default;

private:
    bool isUserExist(const User& user);

private:
    QString name;
    QSqlQuery query;
    std::shared_ptr<IPasswordHasher> hasher;
};

