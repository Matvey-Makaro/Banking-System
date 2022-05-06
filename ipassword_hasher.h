#pragma once

#include<QString>

class IPasswordHasher
{
public:
    virtual QString hash(const QString& password) const = 0;
    virtual ~IPasswordHasher() = default;
};
