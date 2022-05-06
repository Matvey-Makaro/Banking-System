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
    void notAllFieldsAreFilled() const;

private slots:
    void goToRegistration();
    void signIn();

private:
    void goToUserRole(const User& user);
    void goToClientRole(const User& user);
    void goToManagerRole(const User& user);
    void goToOperatorRole(const User& user);
    void goToEnterpriseSpecialist(const User& user);
    void goToAdministratorRole(const User& user);

private:
    std::shared_ptr<AuthorizationView> authorizationView;
    std::shared_ptr<IBank> bank;
    std::shared_ptr<RegistrationPresenter> registrationPresenter;
};

