#pragma once


#include <QWidget>
#include <QtWidgets>

class ClientDepositsPresenter;

class ClientDepositsView : public QWidget
{
    Q_OBJECT
public:
    explicit ClientDepositsView(ClientDepositsPresenter* clientDepositsPresenter, QWidget *parent = nullptr);
    const QPushButton* getDepositInfoBtn() const { return depositInfoBtn; }
    const QPushButton* getOpenDepositBtn() const { return openDepositBtn; }
    const QPushButton* getWithdrawMoneyBtn() const { return withdrawMoneyBtn; }
    int getIdOfSelectedAccount() const { return depositsTableView->currentIndex().data().toInt(); }
    double getDoubleFromClient(const QString& title, const QString& label, double startValue, double minValue, double maxValue, int decimals);
    int getIntFromClinet(const QString& title, const QString& label, int startValue, int minValue, int maxValue, int step);

public slots:
    void showDepositInfo(QString accountInfo);
    void showError(QString error);

private:
    void initUi();

private:
    ClientDepositsPresenter* clientDepositsPresenter;
    QTableView* depositsTableView;
    QPushButton* depositInfoBtn;
    QPushButton* openDepositBtn;
    QPushButton* withdrawMoneyBtn;

};

