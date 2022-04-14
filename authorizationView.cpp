#include "authorizationView.h"


AuthorizationView::AuthorizationView(QWidget *parent) : QWidget(parent)
{
    initUi();
}


const QPushButton* AuthorizationView::getButtonLogIn() const
{
    return pBtnLogIn;
}


void AuthorizationView::initUi()
{
    pLblText = new QLabel("Authorization");
    pLblLogin = new QLabel("Login:");
    pLblPassword = new QLabel("Password:");

    pEdtLogin = new QLineEdit();
    pEdtPassword = new QLineEdit();
    pEdtPassword->setEchoMode(QLineEdit::Password);

    pBtnLogIn = new QPushButton("Log in");

    pVBox = new QVBoxLayout();
    pVBox->addWidget(pLblText);
    pVBox->addWidget(pLblLogin);
    pVBox->addWidget(pEdtLogin);
    pVBox->addWidget(pLblPassword);
    pVBox->addWidget(pEdtPassword);
    pVBox->addWidget(pBtnLogIn);
    setLayout(pVBox);
}
