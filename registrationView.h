#pragma once

#include <QWidget>
#include <QtWidgets>
#include <QStringList>
#include <QString>

class RegistrationView : public QWidget
{
    Q_OBJECT
public:
    explicit RegistrationView(QWidget *parent = nullptr);
    const QPushButton* getSignUpBtn() const { return signUpBtn; }
    QString getName() const { return nameEdit->text(); }
    QString getSurname() const { return surnameEdit->text(); }
    QString getPatronymic() const { return patronymicEdit->text(); }
    QString getPhoneNumber() const { return phoneNumberEdit->text(); }
    QString getEmail() const { return emailEdit->text(); }
    QString getLogin() const { return loginEdit->text(); }
    QString getPassword() const { return passwordEdit->text(); }

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

