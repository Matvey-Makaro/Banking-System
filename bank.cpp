#include "bank.h"
#include "md5_password_hasher.h"
#include "config.h"
#include "client.h"
#include "currency_type.h"
#include "account_status_type.h"

#include <utility>
#include <QDebug>
#include <QSqlError>
#include <QString>
#include <QStringList>
#include <stdexcept>
#include <string>
#include <ctime>

Bank::Bank(QString bankName) :
    name(std::move(bankName)), hasher(std::make_shared<MD5PasswordHasher>())
{

}

void Bank::addUserToApplicationsForRegistration(User& user)
{
    user.setHashedPassword(hasher->hash(user.getPassword()));
    if(isUserExist(user))
        throw std::logic_error("Such user exists.");    // Возможно надо будет заменит на кастомное исключение
    QString str = "INSERT INTO " + name + applicationsForRegistrationPostfix +
            " (login, password, userType, name, surname, patronymic, phoneNumber, email, passport, fromRB) "
            "VALUES('%1', '%2', %3, '%4', '%5', '%6', '%7', '%8', '%9', %10);";
    QString tmp = str.arg(user.getLogin()).arg(user.getHashedPassword()).arg(user.getType()).arg(user.getName()).arg(user.getSurname()).
            arg(user.getPatronymic()).arg(user.getPhoneNumber()).arg(user.getEmail()).arg(user.getPassport()).arg(user.getIsFromRB());
    if(!query.exec(tmp))
    {
        qDebug() << "Error" << query.lastError();
    }


}

User Bank::getUser(QString& login, QString& password) const
{
    QStringList tablesToSearchPostfixs = {CLIENTS_POSTFIX, MANAGERS_POSTFIX, OPERATORS_POSTFIX, ENTERPRISE_SPECIALIST_POSTFIX, ADMINS_POSTFIX};
    QString hashedPassword = hasher->hash(password);
    QString str = "SELECT * FROM " + name + "%1" + " WHERE login = '%2' AND password = '%3'";
    for(const QString& postfix : tablesToSearchPostfixs)
    {
        QString tmp = str.arg(postfix).arg(login).arg(hashedPassword);
        if(!query.exec(tmp))
            qDebug() << "Can't make command: " + tmp << '\n';
        if(query.next())
        {
            int id = query.value("id").toInt();
            QString name = query.value("name").toString();
            QString surname = query.value("surname").toString();
            QString patronymic = query.value("patronymic").toString();
            QString phoneNumber = query.value("phoneNumber").toString();
            QString email = query.value("email").toString();
            QString passport = query.value("passport").toString();
            bool fromRB = query.value("fromRB").toBool();
            UserType type = getUserTypeByPostfix(postfix);
            return User(login, hashedPassword, name, surname, patronymic, phoneNumber, email, passport, fromRB, id, type);
        }
    }
    throw std::invalid_argument("No such user in database.");
}

void Bank::createAccoutForClient(int clientId)
{
    QString str = "INSERT INTO " + name + ACCOUNTS_POSTFIX +
            " (clientId, balance, percent, creationDate, currencyType, status) "
            "VALUES (%1, %2, %3, %4, %5, %6);";
    double balance = 0;
    double percent = 2.4;
    double creationData = std::time(nullptr);
    //TODO: Изменить, чтобы у иностранных клиентов счет в долларах открывался.
    int curType = CurrencyType::BYN;
    int status = AccountStatusType::OPEN;
    QString tmp = str.arg(clientId).arg(balance).arg(percent).arg(creationData).arg(curType).arg(status);
    if(!query.exec(tmp))
        qDebug() << "Can't make command: " + tmp << '\n';
}

QSqlQueryModel& Bank::getClientAccountsModel(int clientId)
{
    if(clientAccountsModel.get() == nullptr)
        clientAccountsModel = std::make_shared<QSqlQueryModel>();
    QString str = "SELECT id FROM " + name + ACCOUNTS_POSTFIX +
            " WHERE clientId = " + std::to_string(clientId).c_str() + ";";
    clientAccountsModel->setQuery(str);
    if(clientAccountsModel->lastError().isValid())
        qDebug() << clientAccountsModel->lastError() << "\n";
    clientAccountsModel->setHeaderData(0, Qt::Horizontal, "Номер счёта");
    return *clientAccountsModel.get();
}

void Bank::updateClientAccountsModel()
{
    clientAccountsModel->setQuery(clientAccountsModel->query().lastQuery());
}

void Bank::closeClientAccount(int accountId) const
{
    QString str = "DELETE FROM " + name + ACCOUNTS_POSTFIX +
            " WHERE id = " + std::to_string(accountId).c_str() + ";";
    if(!query.exec(str))
        qDebug() << "Can't make command: " + str << '\n';
}

Account Bank::getClientAccount(int accountId) const
{
    QString str = "SELECT * FROM " + name + ACCOUNTS_POSTFIX +
            " WHERE id = " + std::to_string(accountId).c_str() + ";";
    if(!query.exec(str))
        qDebug() << "Can't make command: " + str << '\n';
    if(query.next())
    {
        int id = query.value("id").toInt();
        int clientId = query.value("clientId").toInt();
        double balance = query.value("balance").toDouble();
        double percent = query.value("percent").toDouble();
        long long creationDate = query.value("creationDate").toLongLong();
        CurrencyType currencyType = static_cast<CurrencyType>(query.value("currencyType").toInt());
        AccountStatusType statusType = static_cast<AccountStatusType>(query.value("status").toInt());
        return Account(id, clientId, balance, percent, creationDate, currencyType, statusType);
    }
    throw std::logic_error("No such account id in database.");
}

void Bank::putMoneyOnClientAccount(int accountId, double sum)
{
    Account account = getClientAccount(accountId);
    double currentSum = account.getBalance();
    account.setBalance(currentSum + sum);
    QString str = "UPDATE " + name + ACCOUNTS_POSTFIX +
            "SET balance = " + std::to_string(account.getBalance()).c_str() +
            "WHERE id = " + std::to_string(accountId).c_str() + ";";
    if(!query.exec(str))
        qDebug() << "Can't make command: " + str << '\n';
}

const QString& Bank::getName() const { return name; }

bool Bank::isUserExist(const User& user)
{
    QString str = "SELECT * FROM " + name + " WHERE login = '%1'";
    str = str.arg(user.getLogin());
    if(!query.exec(str))
        qDebug() << "Can't make command: " + str << '\n';
    if(query.next())
        return true;
    return false;
}

int Bank::getEnterpriseId(const QString& enterpriseName)
{
    QString str = "SELECT * FROM " + name + enterprisesTableName + " WHERE name = '%1'";
    str = str.arg(enterpriseName);
    if(!query.exec(str))
        qDebug() << "Can't make command: " + str << '\n';
    if(query.next())
        return query.value("id").toInt();
    else
        throw std::logic_error("No such enterprise name");  // обработать данное исключение
}


UserType Bank::getUserTypeByPostfix(const QString& postfix) const
{
    if(postfix == CLIENTS_POSTFIX)
        return UserType::CLIENT;
    if(postfix == MANAGERS_POSTFIX)
        return UserType::MANAGER;
    if(postfix == OPERATORS_POSTFIX)
        return UserType::OPERATOR;
    if(postfix == ENTERPRISE_SPECIALIST_POSTFIX)
        return UserType::ENTERPRISE_SPECIALIST;
    if(postfix == ADMINS_POSTFIX)
        return UserType::ADMINISTRATOR;
    return UserType::UNKNOWN;
}
