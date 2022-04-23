#include "authorizationView.h"
#include "lengthValidator.h"


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

    LengthValidator* lenValidator = new LengthValidator(32, 6, this);
    editLogin->setValidator(lenValidator);
    editPassword->setValidator(lenValidator);

    lblLogin->setBuddy(editLogin);
    lblPassword->setBuddy(editPassword);

    btnSignIn = new QPushButton("Sign in");
    btnSignUp = new QPushButton("Sign up");

    vBox = new QVBoxLayout();
    vBox->addStretch();
    vBox->addWidget(lblText);
    vBox->addWidget(lblLogin);
    vBox->addWidget(editLogin);
    vBox->addWidget(lblPassword);
    vBox->addWidget(editPassword);
    vBox->addWidget(btnSignIn);
    vBox->addWidget(btnSignUp);
    vBox->addStretch();
    setLayout(vBox);
}
