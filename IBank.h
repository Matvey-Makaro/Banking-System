#pragma once

#include "user.h"

class IBank
{
public:
    IBank() = default;
    virtual void createUser() = 0;
};
