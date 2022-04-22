#pragma once

#include "IBank.h"
#include "userType.h"

#include <QString>
#include <QStringList>
#include <QSqlQuery>

class Bank : public IBank
{
public:
    Bank(QString bankName);
    virtual void createUser(const QString& login, const QString& password, const UserType type,
                            const QString& name, const QString& surname, const QString& patronymic,
                            const QString& phoneNumber, const QString& email);
    virtual const QString& getName() const override;
    virtual ~Bank() = default;


private:
    QString name;
    QSqlQuery query;
};

