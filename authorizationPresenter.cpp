#include "authorizationPresenter.h"

AuthorizationPresenter::AuthorizationPresenter(std::shared_ptr<IBank> IBank, QObject *parent) :
    authorizationView(std::make_shared<AuthorizationView>()), bank(IBank), QObject(parent)
{
    authorizationView->show();
    connect(authorizationView->getButtonSignUp(), SIGNAL(clicked()), this, SLOT(goToRegistration()));
}

void AuthorizationPresenter::goToRegistration()
{
    authorizationView->hide();
    registrationPresenter = std::make_shared<RegistrationPresenter>(bank);
}
