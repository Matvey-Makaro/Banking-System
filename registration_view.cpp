#include "registration_view.h"
#include "no_number_validator.h"
#include "length_validator.h"

#include <QRegExpValidator>
#include <QRegExp>

RegistrationView::RegistrationView(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void RegistrationView::warnNotAllFieldsAreFilled()
{
    if(!notAllFieldsAreFilledMsgBox)
        notAllFieldsAreFilledMsgBox = new QMessageBox(QMessageBox::Warning, "Warning", "Not all required fields are filled", QMessageBox::Ok, this);
    notAllFieldsAreFilledMsgBox->exec();
}

void RegistrationView::notifyRegistrationApplicationAccepted()
{
    if(!registrationApplicationAcceptedMsgBox)
        registrationApplicationAcceptedMsgBox = new QMessageBox(QMessageBox::Information, "Запрос отправлен",
                                                                "Ваша заявка будет рассмотрена менеджером. Пожалуйста подождите одобрения заявки",
                                                                QMessageBox::Ok, this);
    registrationApplicationAcceptedMsgBox->exec();
}

void RegistrationView::initUI()
{
    registrationLbl = new QLabel("Registration");
    nameLbl = new QLabel("Name:");
    surnameLbl = new QLabel("Surname:");
    patronymicLbl = new QLabel("Patronymic:");
    phoneNumberLbl = new QLabel("Phone number:");
    emailLbl = new QLabel("Email:");
    passportLbl = new QLabel("Passport:");
    loginLbl = new QLabel("Login:");
    passwordLbl = new QLabel("Password:");

    nameEdit = new QLineEdit();
    surnameEdit = new QLineEdit();
    patronymicEdit = new QLineEdit();
    phoneNumberEdit = new QLineEdit();
    emailEdit = new QLineEdit();
    passportEdit = new QLineEdit();
    loginEdit = new QLineEdit();
    passwordEdit = new QLineEdit();
    passwordEdit->setEchoMode(QLineEdit::Password);

    NoNumberValidator* noNumberValidator = new NoNumberValidator(this);
    nameEdit->setValidator(noNumberValidator);
    surnameEdit->setValidator(noNumberValidator);
    patronymicEdit->setValidator(noNumberValidator);
    QRegExpValidator* phoneNumberValidator = new QRegExpValidator(QRegExp("^\\+\\d{1,12}$"), this);
    phoneNumberEdit->setValidator(phoneNumberValidator);
    QRegExpValidator* emailValidator = new QRegExpValidator(QRegExp("^([a-z0-9_-]+\\.)*[a-z0-9_-]+@[a-z0-9_-]+(\\.[a-z0-9_-]+)*\\.[a-z]{2,6}$"), this);
    emailEdit->setValidator(emailValidator);
    LengthValidator* lenValidator = new LengthValidator(32, 6, this);
    loginEdit->setValidator(lenValidator);
    passwordEdit->setValidator(lenValidator);


    nameLbl->setBuddy(nameEdit);
    surnameLbl->setBuddy(surnameEdit);
    patronymicLbl->setBuddy(patronymicEdit);
    phoneNumberLbl->setBuddy(phoneNumberEdit);
    emailLbl->setBuddy(emailEdit);
    passportLbl->setBuddy(passportEdit);
    loginLbl->setBuddy(loginEdit);
    passwordLbl->setBuddy(passwordEdit);

    fromRBCheckBox = new QCheckBox("Citizen of the Republic of Belarus");

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
    vbox->addWidget(passportLbl);
    vbox->addWidget(passportEdit);
    vbox->addWidget(loginLbl);
    vbox->addWidget(loginEdit);
    vbox->addWidget(passwordLbl);
    vbox->addWidget(passwordEdit);
    vbox->addWidget(fromRBCheckBox);
    vbox->addWidget(signUpBtn);
    vbox->addStretch();

    setLayout(vbox);
}


