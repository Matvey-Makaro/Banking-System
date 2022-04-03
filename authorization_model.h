#pragma once

#include <QObject>

class AuthorizationModel : public QObject
{
    Q_OBJECT
public:
    explicit AuthorizationModel(QObject *parent = nullptr);

private slots:
    bool checkLoginAndPassword();

};

