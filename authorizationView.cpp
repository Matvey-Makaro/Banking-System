#include "authorizationView.h"


AuthorizationView::AuthorizationView(QWidget *parent) : QWidget(parent)
{
    initUi();
}


const QPushButton* AuthorizationView::getButtonSignIn() const { return btnSignIn; }

const QPushButton* AuthorizationView::getButtonSignUp() const { return btnSignUp; }

void AuthorizationView::initUi()
{
    lblText = new QLabel("Authorization");
    lblLogin = new QLabel("Login:");
    lblPassword = new QLabel("Password:");

    editLogin = new QLineEdit();
    editPassword = new QLineEdit();
    editPassword->setEchoMode(QLineEdit::Password);

    btnSignIn = new QPushButton("Sign in");
    btnSignUp = new QPushButton("Sign up");

    vBox = new QVBoxLayout();
    vBox->addWidget(lblText);
    vBox->addWidget(lblLogin);
    vBox->addWidget(editLogin);
    vBox->addWidget(lblPassword);
    vBox->addWidget(editPassword);
    vBox->addWidget(btnSignIn);
    vBox->addWidget(btnSignUp);
    setLayout(vBox);
}
