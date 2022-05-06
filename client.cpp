#include "client.h"

#include <utility>

Client::Client(int id, QString name, QString surname, QString patronymic, QString phoneNumber, QString email, QString passport, bool fromRB):
    id(id), name(std::move(name)), surname(std::move(surname)), patronymic(std::move(patronymic)), phoneNumber(std::move(phoneNumber)),
    email(std::move(email)), passport(std::move(passport)), fromRB(fromRB)
{

}
