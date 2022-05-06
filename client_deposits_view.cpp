#include "client_deposits_view.h"

ClientDepositsView::ClientDepositsView(QWidget *parent) : QWidget(parent)
{
    initUi();
}

void ClientDepositsView::initUi()
{
    setFixedWidth(500);
    setFixedHeight(500);

    setWindowTitle("Working with deposits");

    /*
     * a. Создание
     * b. Закрытие (как только истёк срок вклада, но НЕ РАНЬШЕ)
     * e. Накопление
     * */

    QVBoxLayout *vBoxLayout = new QVBoxLayout(this);

    // TODO: Понять что это и как использовать
    auto depositsListWidget = new QListWidget(this);

    // Здесь нужно получать список вкладов Клиента из базы данных
    // Отображать нужно только их id'шники
    //updateClientDepositsData();
    //updateClientDepositsListWidget();

    depositInfoBtn = new QPushButton("Информация о вкладе", this);
    openDepositBtn = new QPushButton("Открыть новый вклад", this);
    withdrawMoneyBtn = new QPushButton("Вывести деньги", this);

    vBoxLayout->addWidget(depositsListWidget);
    vBoxLayout->addWidget(depositInfoBtn);
    vBoxLayout->addWidget(openDepositBtn);
    vBoxLayout->addWidget(withdrawMoneyBtn);
    setLayout(vBoxLayout);
}
