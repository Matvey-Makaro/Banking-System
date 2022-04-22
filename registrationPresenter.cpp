#include "registrationPresenter.h"

RegistrationPresenter::RegistrationPresenter(std::shared_ptr<IBank> IBank, QObject *parent) :
    bank(IBank), registrationView( std::make_shared<RegistrationView>()), QObject(parent)
{
    registrationView->show();
}
