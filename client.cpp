#include "client.h"

#include <utility>

Client::Client(int id, QString name, QString surname, QString patronymic, QString phoneNumber, QString email,
               QString passport, bool fromRB, std::shared_ptr<IBank> bank):
    id(id), name(std::move(name)), surname(std::move(surname)), patronymic(std::move(patronymic)), phoneNumber(std::move(phoneNumber)),
    email(std::move(email)), passport(std::move(passport)), fromRB(fromRB), currentBank(bank)
{

}

QSqlQueryModel &Client::getAccountQueryModel() const
{
    return currentBank->getClientAccountsModel(id);
}

void Client::updateAccountQueryModel() const
{
    currentBank->updateClientAccountsModel();
}

void Client::openAccount()
{
    currentBank->createAccoutForClient(id);
}

void Client::closeAccount(int accountId)
{
    currentBank->closeClientAccount(accountId);
}

Account Client::getAccount(int accountId)
{
    Account account = currentBank->getClientAccount(accountId);
    account.setClientName(surname + " " + name + " " + patronymic);
    return account;
}

void Client::putMoneyOnAccount(int accountId, double sum)
{
    currentBank->putMoneyOnClientAccount(accountId, sum);
}

void Client::withdrawMoneyFromAccount(int accountId, double sum)
{
    currentBank->withdrawMoneyFromClientAccout(accountId, sum);
}

void Client::transferMoney(int srcAccountId, int dstAccountId, double sum)
{
    currentBank->transferMoney(srcAccountId, dstAccountId, sum);
}

QSqlQueryModel &Client::getDepositQueryModel() const
{
    currentBank->getClientDepositsModel(id);
}

void Client::updateDepositQueryModel() const
{
    currentBank->updateClientDepositsModel();
}
