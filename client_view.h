#pragma once

#include <QWidget>
#include <QtWidgets>

class ClientPresenter;

class ClientView : public QWidget
{
    Q_OBJECT
public:
    explicit ClientView(ClientPresenter* clientPresenter, QWidget *parent = nullptr);
    const QPushButton* getAccountsWorkBtn() const { return accountsWorkBtn; }
    const QPushButton* getDepositsWorkBtn() const { return depositsWorkBtn; }
    const QPushButton* getCreditsBtn() const { return creditsBtn; }
    const QPushButton* getInstallmentsBtn() const { return installmentsBtn; }
    const QPushButton* getSalaryProjectBtn() const { return salaryProjectBtn; }

private:
    void initUI();

private:
    ClientPresenter* clientPresenter;
    QPushButton *accountsWorkBtn;
    QPushButton *depositsWorkBtn;
    QPushButton *creditsBtn;
    QPushButton *installmentsBtn;
    QPushButton *salaryProjectBtn;

};

