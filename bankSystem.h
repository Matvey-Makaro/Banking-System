#pragma once

#include "IBankSystem.h"

#include <QStringList>

class BankSystem : public IBankSystem
{
public:
    BankSystem();
    const QStringList& getBankNames() const override;

private:
    QStringList bankNames;
};

