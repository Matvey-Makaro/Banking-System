#include "main_view.h"

MainView::MainView(QWidget *parent) : QWidget(parent)
{
    initUi();
}


void MainView::initUi()
{
    authorizationView = std::make_shared<AuthorizationView>();
    authorizationView->show();
}
