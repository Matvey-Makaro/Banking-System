#include "currencyconverter.h"

CurrencyConverter::CurrencyConverter()
{
}

double CurrencyConverter::convert(double value, CurrencyType valueCurrency, CurrencyType outputCurrency)
{
    if (valueCurrency == outputCurrency)
    {
        return value;
    }

    if (valueCurrency == BYN)
    {
        return bynToUsd(value);
    }
    else
    {
        return usdToByn(value);
    }
}
