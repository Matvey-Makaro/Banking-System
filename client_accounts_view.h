#pragma once


#include <QWidget>
#include <QtWidgets>
#include <QVariant>


class ClientAccountsPresenter;

class ClientAccountsView : public QWidget
{
    Q_OBJECT
public:
    explicit ClientAccountsView(ClientAccountsPresenter* presenter, QWidget *parent = nullptr);
    const QPushButton* getOpenAccountBtn() const { return openAccountBtn; }
    const QPushButton* getCloseAccountBtn() const { return closeAccountBtn; }
    const QPushButton* getWithdrawBtn() const { return withdrawBtn; }
    const QPushButton* getTransferBtn() const { return transferBtn; }
    const QPushButton* getPutMoneyBtn() const { return putMoneyBtn; }
    const QPushButton* getShowAccInfoBtn() const { return showAccInfoBtn; }
    int getIdOfSelectedAccount() const { return accountsTableView->currentIndex().data().toInt(); }
    double getPutMoneyFromClient();
    double getWithdrawMoneyFromClient();
    int getAccountIdFromClient();
    double getDoubleFromClient(const QString& title, const QString& label, double startValue, double minValue, double maxValue, int decimals);
    int getIntFromClinet(const QString& title, const QString& label, int startValue, int minValue, int maxValue, int step);

public slots:
    void showAccountInfo(QString accountInfo);
    void showError(QString error);

private:
    void initUi();

private:
    ClientAccountsPresenter* clientAccountsPresenter;
    QTableView* accountsTableView;
    QPushButton* openAccountBtn;
    QPushButton* closeAccountBtn;
    QPushButton* withdrawBtn;
    QPushButton* transferBtn;
    QPushButton* putMoneyBtn;
    QPushButton* showAccInfoBtn;

};

