#pragma once

#include <currency_type.h>

class CurrencyConverter
{
public:
    CurrencyConverter();

    static double convert(double value, CurrencyType valueCurrency, CurrencyType outputCurrency);

private:
    static double bynToUsd(double byn) { return byn / 3.0; }
    static double usdToByn(double usd) { return usd * 3.0; }
};
