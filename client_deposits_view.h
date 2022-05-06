#pragma once

#include <QWidget>
#include <QtWidgets>

class ClientDepositsView : public QWidget
{
    Q_OBJECT
public:
    explicit ClientDepositsView(QWidget *parent = nullptr);
    const QPushButton* getDepositInfoBtn() const { return depositInfoBtn; }
    const QPushButton* getOpenDepositBtn() const { return openDepositBtn; }
    const QPushButton* getWithdrawMoneyBtn() const { return withdrawMoneyBtn; }

private:
    void initUi();

private:
    QPushButton* depositInfoBtn;
    QPushButton* openDepositBtn;
    QPushButton* withdrawMoneyBtn;

};

