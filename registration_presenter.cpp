#include "registration_presenter.h"

RegistrationPresenter::RegistrationPresenter(std::shared_ptr<IBank> IBank, QObject *parent) :
    bank(IBank), registrationView( std::make_shared<RegistrationView>()), QObject(parent)
{
    registrationView->show();
    connect(registrationView->getSignUpBtn(), SIGNAL(clicked()), this, SLOT(signUpUser()));
    connect(this, SIGNAL(notAllFieldsAreFilled()), registrationView.get(), SLOT(warnNotAllFieldsAreFilled()));
    connect(this, SIGNAL(registrationApplicationAccepted()), registrationView.get(), SLOT(notifyRegistrationApplicationAccepted()));
}

void RegistrationPresenter::signUpUser() const
{

    User user(registrationView->getLogin(), registrationView->getPassword(), registrationView->getName(), registrationView->getSurname(), registrationView->getPatronymic(),
              registrationView->getPhoneNumber(), registrationView->getEmail(), registrationView->getPassport(), registrationView->isFromRB());
    if(isAllFieldsFilledIn(user))
    {
        bank->addUserToApplicationsForRegistration(user);
        emit registrationApplicationAccepted();
    }
    else
    {
        emit notAllFieldsAreFilled();
    }

}

bool RegistrationPresenter::isAllFieldsFilledIn(const User& user) const
{
    return !(user.getLogin().isEmpty() || user.getPassword().isEmpty() || user.getName().isEmpty() || user.getSurname().isEmpty() ||
            user.getPatronymic().isEmpty() || user.getPhoneNumber().isEmpty() || user.getEmail().isEmpty() || user.getPassport().isEmpty());

}
