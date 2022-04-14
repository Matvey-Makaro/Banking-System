#pragma once

#include <authorizationView.h>

#include <QWidget>

class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = nullptr);

signals:

private:
    void initUi();

private:
    AuthorizationView* authorizationView;


};

