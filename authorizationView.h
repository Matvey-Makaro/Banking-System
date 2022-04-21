#pragma once

#include <QtWidgets>

class AuthorizationView : public QWidget
{
    Q_OBJECT
public:
    explicit AuthorizationView(QWidget *parent = nullptr);

    const QPushButton* getButtonSignIn() const;
    const QPushButton* getButtonSignUp() const;

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


signals:

};

