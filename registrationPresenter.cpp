#include "registrationPresenter.h"
#include "user.h"

RegistrationPresenter::RegistrationPresenter(std::shared_ptr<IBank> IBank, QObject *parent) :
    bank(IBank), registrationView( std::make_shared<RegistrationView>()), QObject(parent)
{
    registrationView->show();
    connect(registrationView->getSignUpBtn(), SIGNAL(clicked()), this, SLOT(signUpUser()));
}

void RegistrationPresenter::signUpUser()
{
    User user(registrationView->getLogin(), registrationView->getPassword(), registrationView->getName(), registrationView->getSurname(),
              registrationView->getPatronymic(), registrationView->getPhoneNumber(), registrationView->getEmail(), "No job yet, correct it");
    bank->addUserToApplicationsForRegistration(user);
}
