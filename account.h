#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "somethingholdingmoney.h"

class Account : public SomethingHoldingMoney
{
public:
    Account(int64_t id, std::string clientLogin, double initialBalance,
            double percents, time_t creationTime, int st, CurrencyType currencyType);

    void accumulate();
    void putMoney(double value) { balance += value; }
    void withdrawMoney(double value) { balance -= value; }

    std::string getInfo() const override;
};

#endif // ACCOUNT_H
