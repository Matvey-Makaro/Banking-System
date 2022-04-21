#include "authorizationPresenter.h"

AuthorizationPresenter::AuthorizationPresenter(IBank& IBank, QObject *parent) :
    authorizationView(new AuthorizationView()), bank(IBank), QObject(parent)
{
    authorizationView->show();
}

AuthorizationPresenter::~AuthorizationPresenter()
{
    if(authorizationView != nullptr)
        delete authorizationView;
}


