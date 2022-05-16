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

public slots:
    void showAccountInfo(QString accountInfo);




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

