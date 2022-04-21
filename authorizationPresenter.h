#pragma once

#include "authorizationView.h"
#include "IBank.h"

#include <QObject>

class AuthorizationPresenter : public QObject
{
    Q_OBJECT
public:
    explicit AuthorizationPresenter(IBank& bank, QObject *parent = nullptr);
    ~AuthorizationPresenter();

signals:

private:
    AuthorizationView* authorizationView;
    IBank& bank;
};

