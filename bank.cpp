#include "bank.h"
#include "md5PasswordHasher.h"
#include "config.h"

#include <utility>
#include <QDebug>
#include <QSqlError>
#include <QString>
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
    user.setEnterpriseId(getEnterpriseId(user.getPlaceOfWork()));
    QString str = "INSERT INTO " + name + " " + applicationsForRegistrationPostfix + 
            " (login, password, userType, name, surname, patronymic, phoneNumber, email, enterpiseId) "
            "VALUES('%1', '%2', %3, '%4', '%5', '%6', '%7', '%8', %9);";
    QString tmp = str.arg(user.getLogin()).arg(user.getHashedPassword()).arg(user.getType()).arg(user.getName()).
            arg(user.getSurname()).arg(user.getPatronymic()).arg(user.getPhoneNumber()).arg(user.getEmail()).arg(user.getEnterpriseId());
    if(!query.exec(tmp))
    {
        qDebug() << "Error" << query.lastError();
    }


}

void Bank::addUserToApplicationsForRegistration(const QString& login, const QString& password, const UserType type, const QString& userName,
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
