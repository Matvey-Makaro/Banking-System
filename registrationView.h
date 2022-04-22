#pragma once

#include <QWidget>
#include <QtWidgets>
#include <QStringList>

class RegistrationView : public QWidget
{
    Q_OBJECT
public:
    explicit RegistrationView(QWidget *parent = nullptr);
    const QPushButton* getSignUpBtn() const;

signals:

private:
    void initUI();

private:
    QLabel* registrationLbl;
    QLabel* nameLbl;
    QLabel* surnameLbl;
    QLabel* patronymicLbl;
    QLabel* phoneNumberLbl;
    QLabel* emailLbl;
    QLabel* loginLbl;
    QLabel* passwordLbl;
    QLabel* repeatPasswordLbl;
    QLineEdit* nameEdit;
    QLineEdit* surnameEdit;
    QLineEdit* patronymicEdit;
    QLineEdit* phoneNumberEdit;
    QLineEdit* emailEdit;
    QLineEdit* loginEdit;
    QLineEdit* passwordEdit;
    QLineEdit* repeatPasswordEdit;
    QPushButton* signUpBtn;

};

