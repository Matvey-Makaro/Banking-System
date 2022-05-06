#include "clientView.h"

#include <QtWidgets>
#include <clientPresenter.h>
#include <string>

ClientView::ClientView(ClientPresenter* clientPresenter, QWidget *parent) :
    clientPresenter(clientPresenter), QWidget(parent)
{
    initUI();
}


void ClientView::initUI()
{
    setFixedWidth(600);
    setFixedHeight(500);

    setWindowTitle("Client's personal account");

    QGridLayout *gridLayout = new QGridLayout(this);

    QLabel *userInfoLabel = new QLabel(this);
    userInfoLabel->setText("User information:");

    QTableWidget *infoTable = new QTableWidget(this);
    infoTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    infoTable->setRowCount(6);
    infoTable->setColumnCount(2);
    infoTable->setItem(0, 0, new QTableWidgetItem("Full name"));
    infoTable->setItem(1, 0, new QTableWidgetItem("Id"));
    infoTable->setItem(2, 0, new QTableWidgetItem("Email"));
    infoTable->setItem(3, 0, new QTableWidgetItem("Phone number"));
    infoTable->setItem(4, 0, new QTableWidgetItem("Series and passport number"));
    infoTable->setItem(5, 0, new QTableWidgetItem("Foreign client?"));

    infoTable->setItem(0, 1, new QTableWidgetItem(clientPresenter->getSurname() + " " + clientPresenter->getName() +
                                                  " " + clientPresenter->getPatronymic()));
    infoTable->setItem(1, 1, new QTableWidgetItem(std::to_string(clientPresenter->getId()).c_str()));
    infoTable->setItem(2, 1, new QTableWidgetItem(clientPresenter->getEmail()));
    infoTable->setItem(3, 1, new QTableWidgetItem(clientPresenter->getPhoneNumber()));
    infoTable->setItem(4, 1, new QTableWidgetItem(clientPresenter->getPassport()));
    infoTable->setItem(5, 1, new QTableWidgetItem(clientPresenter->isFromRB() ? "Нет" : "Да"));

    infoTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QPushButton *accountsWork = new QPushButton("Счета", this);
//    connect(accountsWork, &QPushButton::clicked, this, &ClientPersonalAccountWindow::showClientAccountsWindow);

    QPushButton *depositsWork = new QPushButton("Вклады", this);
//    connect(depositsWork, &QPushButton::clicked, this, &ClientPersonalAccountWindow::showClientDepositsWindow);

    QPushButton *credits = new QPushButton("Кредиты", this);
//    connect(credits, &QPushButton::clicked, this, &ClientPersonalAccountWindow::showClientCreditsWindow);

    QPushButton *installments = new QPushButton("Рассрочки", this);
//    connect(installments, &QPushButton::clicked, this, &ClientPersonalAccountWindow::showClientInstallmentsWindow);

    QPushButton *salaryProject = new QPushButton("Зарплатный проект", this);
//    connect(salaryProject, &QPushButton::clicked, this, &ClientPersonalAccountWindow::showSalaryProjectWindow);

    gridLayout->addWidget(userInfoLabel, 0, 0);
    gridLayout->addWidget(infoTable, 1, 0);
    gridLayout->addWidget(accountsWork, 2, 0);
    gridLayout->addWidget(depositsWork, 3, 0);
    gridLayout->addWidget(credits, 4, 0);
    gridLayout->addWidget(installments, 5, 0);
    gridLayout->addWidget(salaryProject, 6, 0);
    setLayout(gridLayout);
}
