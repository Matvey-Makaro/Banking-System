#include "deposit.h"


Deposit::Deposit(int id, int clientId, double balance, double percent, time_t creationDate, time_t lastAccrualOfInterestTime,
                 unsigned term,  CurrencyType currencyType, DepositStatus status) :
    id(id), clientId(clientId), balance(balance), percent(percent), creationDate(creationDate),
    lastAccrualOfInterestTime(lastAccrualOfInterestTime), term(term), currencyType(currencyType), status(status)
{

}

QString Deposit::getInfo() const
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

    switch (status) {
    case DepositStatus::OPEN:
        info += "открыт\n";
        break;
    case DepositStatus::CLOSE:
        info += "закрыт\n";
        break;
    default:
        throw std::logic_error("Unknow status for account.");
    }

    info += "Последнее накопление по процентам: " + std::string(ctime(&lastAccrualOfInterestTime));
    info += "Срок вклада: " + std::to_string(term) + " мес.\n";
    return QString(info.c_str());
}
