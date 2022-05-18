#include "client_deposits_view.h"
#include "client_deposits_presenter.h"

ClientDepositsView::ClientDepositsView(ClientDepositsPresenter* clientDepositsPresenter, QWidget *parent) :
    clientDepositsPresenter(clientDepositsPresenter) ,QWidget(parent)
{
    initUi();
}

void ClientDepositsView::showDepositInfo(QString accountInfo)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Информация о вкладе");
    msgBox.setText(accountInfo);
    msgBox.exec();
}

void ClientDepositsView::showError(QString error)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Ошибка");
    msgBox.setText(error);
    msgBox.exec();
}

double ClientDepositsView::getDoubleFromClient(const QString &title, const QString &label, double startValue, double minValue, double maxValue, int decimals)
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

int ClientDepositsView::getIntFromClinet(const QString &title, const QString &label, int startValue, int minValue, int maxValue, int step)
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

void ClientDepositsView::initUi()
{
    setFixedWidth(500);
    setFixedHeight(500);

    setWindowTitle("Работа с вкладами");

    /*
     * a. Создание
     * b. Закрытие (как только истёк срок вклада, но НЕ РАНЬШЕ)
     * e. Накопление
     * */

    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);

    depositsTableView = new QTableView(this);
    depositsTableView->setModel(&clientDepositsPresenter->getDepositsQueryModel());

    depositInfoBtn = new QPushButton("Информация о вкладе", this);
    openDepositBtn = new QPushButton("Открыть новый вклад", this);
    withdrawMoneyBtn = new QPushButton("Вывести деньги", this);

    vBoxLayout->addWidget(depositsTableView);
    vBoxLayout->addWidget(depositInfoBtn);
    vBoxLayout->addWidget(openDepositBtn);
    vBoxLayout->addWidget(withdrawMoneyBtn);
    setLayout(vBoxLayout);
}
