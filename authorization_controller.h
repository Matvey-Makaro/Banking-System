#pragma once

#include <QObject>

#include "authorization_view.h"
#include "authorization_model.h"

class AuthorizationController : public QObject
{
    Q_OBJECT
public:
    explicit AuthorizationController(AuthorizationView& authorizationView, AuthorizationModel& authorizationModel, QObject *parent = nullptr);

private:
    AuthorizationView& view;
    AuthorizationModel& model;

};

