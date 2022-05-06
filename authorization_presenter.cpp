#include "authorization_presenter.h"
#include "iclient.h"
#include "client.h"

AuthorizationPresenter::AuthorizationPresenter(std::shared_ptr<IBank> IBank, QObject *parent) :
    authorizationView(std::make_shared<AuthorizationView>()), bank(IBank), QObject(parent)
{
    authorizationView->show();
    connect(authorizationView->getButtonSignUp(), SIGNAL(clicked()), this, SLOT(goToRegistration()));
    connect(authorizationView->getButtonSignIn(), SIGNAL(clicked()), this, SLOT(signIn()));
    connect(this, SIGNAL(notAllFieldsAreFilled()), authorizationView.get(), SLOT(warnNotAllFieldsAreFilled()));
}

void AuthorizationPresenter::goToRegistration()
{
    // authorizationView->hide();
    registrationPresenter = std::make_shared<RegistrationPresenter>(bank);
}


void AuthorizationPresenter::signIn()
{
    QString login = authorizationView->getLogin();
    QString password = authorizationView->getPassword();
    if(login.isEmpty() || password.isEmpty())
    {
        emit notAllFieldsAreFilled();
    }
    else
    {
        try
        {
            User user = bank->getUser(login, password);
            goToUserRole(user);
        }
        catch(std::logic_error& ex) //TODO: Изменить на кастомное исключение(Отсутсвие пользователя в базе данных).
        {
            //TODO: Показывать msgBox неверный логин или пароль
            qDebug() << ex.what() << "\n";
        }

    }

}

void AuthorizationPresenter::goToUserRole(const User& user)
{
    if(user.getType() == UserType::CLIENT)
        return goToClientRole(user);
    if(user.getType() == UserType::MANAGER)
        return goToManagerRole(user);
    if(user.getType() == UserType::OPERATOR)
        return goToOperatorRole(user);
    if(user.getType() == UserType::ENTERPRISE_SPECIALIST)
        return goToEnterpriseSpecialist(user);
    if(user.getType() == UserType::ADMINISTRATOR)
        return goToAdministratorRole(user);
    throw std::logic_error("Unknown role"); //TODO: Изменить на кастомное исключение
}

void AuthorizationPresenter::goToClientRole(const User& user)
{
    qDebug() << "Go to client role\n";
    std::shared_ptr<IClient> client = std::make_shared<Client>(user.getId(), user.getName(), user.getSurname(), user.getPatronymic(), user.getPhoneNumber(),
                                   user.getEmail(), user.getPassport(), user.getIsFromRB(), bank);
    clientPresenter = std::make_shared<ClientPresenter>(client);


}

void AuthorizationPresenter::goToManagerRole(const User& user)
{
    qDebug() << "Go to manager role\n";
}

void AuthorizationPresenter::goToOperatorRole(const User& user)
{
    qDebug() << "Go to operator role\n";
}

void AuthorizationPresenter::goToEnterpriseSpecialist(const User& user)
{
    qDebug() << "Go to enterprise specialist role\n";
}

void AuthorizationPresenter::goToAdministratorRole(const User& user)
{
    qDebug() << "Go to administrator role\n";
}
