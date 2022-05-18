#include "client_accounts_view.h"
#include "client_accounts_presenter.h"

#include <QVBoxLayout>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>

ClientAccountsView::ClientAccountsView(ClientAccountsPresenter* presenter, QWidget *parent) :
    clientAccountsPresenter(presenter), QWidget(parent)
{
    initUi();
}

double ClientAccountsView::getPutMoneyFromClient()
{
    QInputDialog inpDialog;
    bool ok;
    double inpMoney;
    QString text = "Введите сумму пополнения";
    inpMoney = inpDialog.getDouble(this, "Положить деньги", text,
                                   0.0,
                                   0.0,
                                   1000,
                                   2,
                                   &ok);
    if(ok)
        return inpMoney;
    else return 0.0;
}

double ClientAccountsView::getWithdrawMoneyFromClient()
{
    QInputDialog inpDialog;
    bool ok;
    double inpMoney;
    QString text = "Введите сумму, которую хотите снять";
    inpMoney = inpDialog.getDouble(this, "Снять деньги", text,
                                   0.0,
                                   0.0,
                                   1000,
                                   2,
                                   &ok);
    if(ok)
        return inpMoney;
    else return 0.0;
}

int ClientAccountsView::getAccountIdFromClient()
{
    QInputDialog inpDialog;
    bool ok;
    QString text = "Введите номер счёта";
    int accountId = inpDialog.getInt(this, "Перевести деньги", text,
                                     0,
                                     0,
                                     2147483647,
                                     1,
                                     &ok);
    if(ok)
        return accountId;
    else
        return -1;
}

double ClientAccountsView::getDoubleFromClient(const QString &title, const QString &label, double startValue, double minValue, double maxValue, int decimals)
{
    QInputDialog inpDialog;
        bool ok;
        double value = inpDialog.getDouble(this, title, label,
                                       startValue,
                                       minValue,
                                       maxValue,
                                       decimals,
                                       &ok);
        if(ok)
            return value;
        else return 0.0;
}

int ClientAccountsView::getIntFromClinet(const QString &title, const QString &label, int startValue, int minValue, int maxValue, int step)
{
    QInputDialog inpDialog;
        bool ok;
        double value = inpDialog.getInt(this, title, label,
                                       startValue,
                                       minValue,
                                       maxValue,
                                       step,
                                       &ok);
        if(ok)
            return value;
        else return -1;
}

void ClientAccountsView::showAccountInfo(QString accountInfo)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Информация о счёте");
    msgBox.setText(accountInfo);
    msgBox.exec();
}

void ClientAccountsView::showError(QString error)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Ошибка");
    msgBox.setText(error);
    msgBox.exec();
}


void ClientAccountsView::initUi()
{
    setFixedWidth(500);
    setFixedHeight(500);

    setWindowTitle("Работа со счетами");

    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);

    accountsTableView = new QTableView(this);

    accountsTableView->setModel(&clientAccountsPresenter->getAccountsQueryModel());


    openAccountBtn = new QPushButton("Открыть новый счёт", this);
    closeAccountBtn = new QPushButton("Закрыть счёт", this);
    withdrawBtn = new QPushButton("Снять деньги", this);
    transferBtn = new QPushButton("Перевести деньги", this);
    putMoneyBtn = new QPushButton("Положить деньги", this);
    showAccInfoBtn = new QPushButton("Информация о счёте", this);


    vBoxLayout->addWidget(accountsTableView);
    vBoxLayout->addWidget(showAccInfoBtn);
    vBoxLayout->addWidget(openAccountBtn);
    vBoxLayout->addWidget(closeAccountBtn);
    vBoxLayout->addWidget(withdrawBtn);
    vBoxLayout->addWidget(transferBtn);
    vBoxLayout->addWidget(putMoneyBtn);
    setLayout(vBoxLayout);
}
