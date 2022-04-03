#include "authorization_controller.h"

AuthorizationController::AuthorizationController(AuthorizationView& authorizationView, AuthorizationModel& authorizationModel, QObject *parent) :
    view(authorizationView), model(authorizationModel), QObject(parent)
{
    QObject::connect(authorizationView.getButtonLogIn(), SIGNAL(clicked(bool)), &model, SLOT(checkLoginAndPassword()));
    view.show();
}
