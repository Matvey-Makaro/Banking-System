#pragma once

#include <QtWidgets>

class AuthorizationView : public QWidget
{
    Q_OBJECT
public:
    explicit AuthorizationView(QWidget *parent = nullptr);

    QPushButton* getButtonLogIn() const;

private:
    void initUi();

private:
    QVBoxLayout* pVBox;
    QLabel* pLblText;
    QLabel* pLblLogin;
    QLabel* pLblPassword;
    QLineEdit* pEdtLogin;
    QLineEdit* pEdtPassword;
    QPushButton* pBtnLogIn;


signals:

};

