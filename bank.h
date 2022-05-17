#pragma once

#include "ibank.h"
#include "user_type.h"
#include "user.h"
#include "ipassword_hasher.h"
#include "iclient.h"
#include "account.h"

#include <QString>
#include <QStringList>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <memory>

class Bank : public IBank
{
public:
    Bank(QString bankName);
    virtual void addUserToApplicationsForRegistration(User& user) override;
    virtual User getUser(QString& login, QString& password) const override;
    // void approveRegistration(const User& user);
    virtual void createAccoutForClient(int clientId) override;
    virtual QSqlQueryModel& getClientAccountsModel(int clientId) override;
    virtual void updateClientAccountsModel() override;
    virtual void closeClientAccount(int accountId) const override;
    virtual Account getClientAccount(int accountId) const override;
    virtual void putMoneyOnClientAccount(int accountId, double sum) override;
    virtual void withdrawMoneyFromClientAccout(int accountId, double sum) override;
    virtual void transferMoney(int srcAccountId, int dstAccountId, double sum) override;
    virtual const QString& getName() const override;
    virtual ~Bank() = default;

private:
    bool isUserExist(const User& user);
    int getEnterpriseId(const QString& enterpriseName);
    UserType getUserTypeByPostfix(const QString& postfix) const;
    void changeSumOnClientAccount(int accountId, double sum);

private:
    QString name;
    mutable QSqlQuery query;
    std::shared_ptr<IPasswordHasher> hasher;
    std::shared_ptr<QSqlQueryModel> clientAccountsModel;
};

