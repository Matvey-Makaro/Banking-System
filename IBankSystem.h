#pragma once

#include "IBank.h"

class IBankSystem
{
public:
    virtual const QStringList& getBankNames() const;
    // virtual IBank& getBank() = 0;

};
