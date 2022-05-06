#include "authorizationView.h"
#include "lengthValidator.h"


AuthorizationView::AuthorizationView(QWidget *parent) : QWidget(parent)
{
    initUi();
}


void AuthorizationView::warnNotAllFieldsAreFilled()
{
    if(!notAllFieldsAreFilledMsgBox)
        notAllFieldsAreFilledMsgBox = new QMessageBox(QMessageBox::Warning, "Warning", "Not all required fields are filled", QMessageBox::Ok, this);
    notAllFieldsAreFilledMsgBox->exec();
}


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
