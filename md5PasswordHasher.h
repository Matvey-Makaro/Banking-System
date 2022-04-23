#pragma once

#include "IPasswordHasher.h"

#include <QString>
#include <QCryptographicHash>


class MD5PasswordHasher : public IPasswordHasher
{
public:
    virtual QString hash(const QString &password) const override
    {
        return QCryptographicHash::hash(password.toLatin1(), QCryptographicHash::Md5).toHex();
    }
};
