#pragma once

#include "authorizationView.h"
#include "IBank.h"
#include "registrationPresenter.h"

#include <QObject>
#include <memory>

class AuthorizationPresenter : public QObject
{
    Q_OBJECT
public:
    explicit AuthorizationPresenter(std::shared_ptr<IBank> bank, QObject *parent = nullptr);
    ~AuthorizationPresenter() = default;

signals:

private slots:
    void goToRegistration();

private:
    std::shared_ptr<AuthorizationView> authorizationView;
    std::shared_ptr<IBank> bank;
    std::shared_ptr<RegistrationPresenter> registrationPresenter;
};

