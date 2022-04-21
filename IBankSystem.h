#pragma once

#include "IBank.h"

#include <QString>
#include <QStringList>
#include <memory>

class IBankSystem
{
public:
    virtual const QStringList& getBankNames() const = 0;
    virtual std::shared_ptr<IBank> getBank(const QString& bankName) = 0;
    virtual ~IBankSystem() = default;
};
