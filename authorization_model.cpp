#include "authorization_model.h"

#include <QDebug>

AuthorizationModel::AuthorizationModel(QObject *parent) : QObject(parent)
{

}


bool AuthorizationModel::checkLoginAndPassword()
{
    qDebug() << "Check login and password.\n";
    return true;
}
