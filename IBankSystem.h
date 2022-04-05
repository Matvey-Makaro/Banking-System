#pragma once

#include "IBank.h"

class IBankSystem
{
public:
    virtual IBank& getBank() = 0;
};
