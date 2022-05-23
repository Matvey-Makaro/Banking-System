#include "operatorpersonalaccountwindow.h"


OperatorPersonalAccountWindow::OperatorPersonalAccountWindow(IBankSystemModel *bankSystem, QWidget *parent) :
    bankSystemModel(bankSystem), QDialog(parent)
{
    setFixedWidth(500);
    setFixedHeight(500);

    setWindowTitle("Личный кабинет оператора");

    QGridLayout* gridLayout = new QGridLayout(this);

    QLabel* userInfoLabel = new QLabel(this);
    userInfoLabel->setText("Информация:");

    infoTable = new QTableWidget(this);
    infoTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    infoTable->setRowCount(4);
    infoTable->setColumnCount(2);
    infoTable->setItem(0, 0, new QTableWidgetItem("Имя"));
    infoTable->setItem(1, 0, new QTableWidgetItem("Id"));
    infoTable->setItem(2, 0, new QTableWidgetItem("Email"));
    infoTable->setItem(3, 0, new QTableWidgetItem("Телефон"));

    infoTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QPushButton *viewStatistics = new QPushButton("Просмотреть статистику", this);
    // connect(showClientsSignupRequests, &QPushButton::pressed, this, &ManagerPersonalAccountWindow::showSignupRequests);
    QPushButton* viewPayrollRequests = new QPushButton("Запросы на зарплатный проект", this);

    gridLayout->addWidget(userInfoLabel, 0, 0);
    gridLayout->addWidget(infoTable, 1, 0);
    gridLayout->addWidget(viewStatistics, 2, 0);
    gridLayout->addWidget(viewPayrollRequests, 3, 0);
}

void OperatorPersonalAccountWindow::setCurrentOperatorData(Operator *op)
{
    // Здесь должна обновляться информация о пользователе в таблице

    if (oper)
    {
        delete oper;
    }
    oper = op;

    infoTable->setItem(0, 1, new QTableWidgetItem(op->getName().c_str()));
    infoTable->setItem(1, 1, new QTableWidgetItem(std::to_string(op->getId()).c_str()));
    infoTable->setItem(2, 1, new QTableWidgetItem(op->getEmail().c_str()));
    infoTable->setItem(3, 1, new QTableWidgetItem(op->getPhone().c_str()));
}


