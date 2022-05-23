#include "adminpersonalaccountwindow.h"
#include "adminaccountsdepositswindow.h"
#include "ibanksystemmodel.h"

#include <QMessageBox>
#include <QGridLayout>
#include <QLabel>
#include <QTableWidget>
#include <QPushButton>

AdminPersonalAccountWindow::AdminPersonalAccountWindow(IBankSystemModel *bankSystem)
    : bankSystemModel(bankSystem)
{
    setFixedWidth(500);
    setFixedHeight(500);

    setWindowTitle("Личный кабинет администратора");

    QGridLayout *gridLayout = new QGridLayout(this);

    QPushButton *accountsDepositsWork = new QPushButton("Счета и вклады", this);
    connect(accountsDepositsWork, &QPushButton::clicked, this, &AdminPersonalAccountWindow::showAccountsDepositsWindow);
    QPushButton* cancleEverything = new QPushButton("Отменить все действия", this);
    connect(cancleEverything, &QPushButton::clicked, this, &AdminPersonalAccountWindow::cancleEverything);

    gridLayout->addWidget(accountsDepositsWork, 0, 0);
    gridLayout->addWidget(cancleEverything, 1, 0);
}

void AdminPersonalAccountWindow::showAccountsDepositsWindow()
{
    AdminAccountsDepositsWindow window(bankSystemModel);
    window.setWindowModality(Qt::ApplicationModal);
    window.exec();
}

void AdminPersonalAccountWindow::cancleEverything()
{
    bankSystemModel->cancleEverything();
    QMessageBox msgBox;
    msgBox.setWindowTitle("");
    msgBox.setText("Отмена всех действий прошла успешно.");
    msgBox.exec();
}
