#include "mainView.h"

MainView::MainView(QWidget *parent) : QWidget(parent)
{
    initUi();
}


void MainView::initUi()
{
    authorizationView = new AuthorizationView();
    authorizationView->show();
}
