#include "bank.h"
#include "md5PasswordHasher.h"
#include "config.h"
#include <client.h>

#include <utility>
#include <QDebug>
#include <QSqlError>
#include <QString>
#include <QStringList>
#include <stdexcept>

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
        QString tmp = str.arg(name + postfix).arg(login).arg(hashedPassword);
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
