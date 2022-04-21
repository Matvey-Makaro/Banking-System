#pragma once

#include "IBank.h"

#include <QString>
#include <QStringList>

class IBankSystem
{
public:
    virtual const QStringList& getBankNames() const = 0;
    virtual IBank& getBank(const QString& bankName) = 0;
    virtual ~IBankSystem() = default;
};
