#pragma once

#include "IBank.h"
#include "userType.h"
#include "user.h"
#include "IPasswordHasher.h"
#include "IClient.h"

#include <QString>
#include <QStringList>
#include <QSqlQuery>
#include <memory>

class Bank : public IBank
{
public:
    Bank(QString bankName);
    virtual void addUserToApplicationsForRegistration(User& user) override;
    virtual User getUser(QString& login, QString& password) const override;
    // void approveRegistration(const User& user);
    virtual const QString& getName() const override;
    virtual ~Bank() = default;

private:
    bool isUserExist(const User& user);
    int getEnterpriseId(const QString& enterpriseName);
    UserType getUserTypeByPostfix(const QString& postfix) const;

private:
    QString name;
    mutable QSqlQuery query;
    std::shared_ptr<IPasswordHasher> hasher;
};

