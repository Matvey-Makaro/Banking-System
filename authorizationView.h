#pragma once

#include <QtWidgets>
#include <QString>

class AuthorizationView : public QWidget
{
    Q_OBJECT
public:
    explicit AuthorizationView(QWidget *parent = nullptr);

    const QPushButton* getButtonSignIn() const  { return btnSignIn; }
    const QPushButton* getButtonSignUp() const { return btnSignUp; }
    QString getLogin() { return editLogin->text(); }
    QString getPassword() { return editPassword->text(); }

public slots:
    void warnNotAllFieldsAreFilled();


private:
    void initUi();

private:
    QVBoxLayout* vBox;
    QLabel* lblText;
    QLabel* lblLogin;
    QLabel* lblPassword;
    QLineEdit* editLogin;
    QLineEdit* editPassword;
    QPushButton* btnSignIn;
    QPushButton* btnSignUp;
    QMessageBox* notAllFieldsAreFilledMsgBox = nullptr;
};

