#ifndef ADMINPERSONALACCOUNTWINDOW_H
#define ADMINPERSONALACCOUNTWINDOW_H

#include <QDialog>

class IBankSystemModel;

class AdminPersonalAccountWindow : public QDialog
{
    Q_OBJECT
public:
    AdminPersonalAccountWindow(IBankSystemModel *bankSystem);

private slots:
    void showAccountsDepositsWindow();
    void cancleEverything();

private:
    IBankSystemModel *bankSystemModel;
};

#endif // ADMINPERSONALACCOUNTWINDOW_H
