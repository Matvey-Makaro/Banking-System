#include "account.h"
#include "currency_type.h"
#include "account_status_type.h"

#include <string>

Account::Account(int id, int clientId, double balance, double percent, time_t creationData, CurrencyType currencyType, AccountStatusType statusType):
    id(id), clientId(clientId), balance(balance), creationDate(creationData), currencyType(currencyType), statusType(statusType)
{

}

int Account::getId() const
{
    return id;
}

int Account::getClientId() const
{
    return clientId;
}

double Account::getBalance() const
{
    return balance;
}

void Account::setBalance(double value)
{
    balance = value;
}

double Account::getPercent() const
{
    return percent;
}

void Account::setPercent(double value)
{
    percent = value;
}

double Account::getCreationDate() const
{
    return creationDate;
}

CurrencyType Account::getCurrencyType() const
{
    return currencyType;
}

void Account::setCurrencyType(const CurrencyType &value)
{
    currencyType = value;
}

AccountStatusType Account::getStatusType() const
{
    return statusType;
}

void Account::setStatusType(const AccountStatusType &value)
{
    statusType = value;
}

QString Account::getInfo() const
{
    std::string info;
    info += "ID: " + std::to_string(id) + "\n";
    info += "Принадлежит: " + clientName.toStdString()+ "\n";
    info += "Баланс: " + std::to_string(balance);
    info += (currencyType == CurrencyType::BYN ? " BYN" : " $");
    info += "\n";
    info += "Процентная ставка: " + std::to_string(percent) + "\n";
    info += "Последнее накопление по процентам: " + std::string(ctime(&creationDate));

    info += "Статус: ";

    switch (statusType) {
    case AccountStatusType::OPEN:
        info += "открыт\n";
        break;
    case AccountStatusType::FROZEN:
        info += "заморожен\n";
        break;
    case AccountStatusType::BLOCKED:
        info  += "заблокирован\n";
    default:
        throw std::logic_error("Unknow status for account.");
    }
    return QString(info.c_str());
}

QString Account::getClientName() const
{
    return clientName;
}

void Account::setClientName(const QString &value)
{
    clientName = value;
}
