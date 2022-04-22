#include "registrationView.h"

RegistrationView::RegistrationView(QWidget *parent) : QWidget(parent)
{
    initUI();
}

const QPushButton* RegistrationView::getSignUpBtn() const { return signUpBtn; }

void RegistrationView::initUI()
{
    registrationLbl = new QLabel("Registration");
    nameLbl = new QLabel("Name:");
    surnameLbl = new QLabel("Surname:");
    patronymicLbl = new QLabel("Patronymic:");
    phoneNumberLbl = new QLabel("Phone number:");
    emailLbl = new QLabel("Email:");
    loginLbl = new QLabel("Login:");
    passwordLbl = new QLabel("Password:");
    repeatPasswordLbl = new QLabel("Repeat password:");

    nameEdit = new QLineEdit();
    surnameEdit = new QLineEdit();
    patronymicEdit = new QLineEdit();
    phoneNumberEdit = new QLineEdit();
    emailEdit = new QLineEdit();;
    loginEdit = new QLineEdit();;
    passwordEdit = new QLineEdit();
    passwordEdit->setEchoMode(QLineEdit::Password);
    repeatPasswordEdit = new QLineEdit();
    repeatPasswordEdit->setEchoMode(QLineEdit::Password);

    signUpBtn = new QPushButton("Sign up");

    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->addStretch();
    vbox->addWidget(registrationLbl);
    vbox->addWidget(nameLbl);
    vbox->addWidget(nameEdit);
    vbox->addWidget(surnameLbl);
    vbox->addWidget(surnameEdit);
    vbox->addWidget(patronymicLbl);
    vbox->addWidget(patronymicEdit);
    vbox->addWidget(phoneNumberLbl);
    vbox->addWidget(phoneNumberEdit);
    vbox->addWidget(emailLbl);
    vbox->addWidget(emailEdit);
    vbox->addWidget(loginLbl);
    vbox->addWidget(loginEdit);
    vbox->addWidget(passwordLbl);
    vbox->addWidget(passwordEdit);
    vbox->addWidget(repeatPasswordLbl);
    vbox->addWidget(repeatPasswordEdit);
    vbox->addWidget(signUpBtn);
    vbox->addStretch();

    setLayout(vbox);

}
