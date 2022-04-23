#include "bank.h"
#include "md5PasswordHasher.h"

#include <utility>
#include <QDebug>
#include <QSqlError>
#include <QString>

Bank::Bank(QString bankName) :
    name(std::move(bankName)), hasher(std::make_shared<MD5PasswordHasher>())
{

}

void Bank::createUser(User& user)
{
    user.setHashedPassword(hasher->hash(user.getPassword()));

}

void Bank::createUser(const QString& login, const QString& password, const UserType type, const QString& userName,
                      const QString& userSurname, const QString& userPatronymic, const QString& phoneNumber, const QString& email)
{
    QString str = "INSERT INTO " + name + " (login, password, userType, name, surname,"
            "patronymic, phoneNumber, email)"
            "VALUES('%1', '%2', %3, '%4', '%5', '%6', '%7', '%8');";

    QString tmp = str.arg(login).arg(password).arg(type).arg(userName).arg(userSurname).arg(userPatronymic).arg(phoneNumber).arg(email);    
    if(!query.exec(tmp))
        qDebug() << "Error " << query.lastError();
}

const QString& Bank::getName() const { return name; }

bool Bank::isUserExist(const User& user)
{
    QString str = "SELECT * FROM " + name + " WHERE login = '%1'";
    str = str.arg(user.getLogin());
    if(!query.exec(str))
        qDebug() << "Can't make command: " + str << '\n';
    size_t counter = 0;
    if(query.next())
        return true;
    return false;
}
