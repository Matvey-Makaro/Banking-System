#pragma once

#include <QWidget>
#include <QtWidgets>

class ClientAccountsView : public QWidget
{
    Q_OBJECT
public:
    explicit ClientAccountsView(QWidget *parent = nullptr);
    const QPushButton* getOpenAccountBtn() const { return openAccountBtn; }
    const QPushButton* getCloseAccountBtn() const { return closeAccountBtn; }
    const QPushButton* getWithdrawBtn() const { return withdrawBtn; }
    const QPushButton* getTransferBtn() const { return transferBtn; }
    const QPushButton* getPutMoneyBtn() const { return putMoneyBtn; }
    const QPushButton* getShowAccInfoBtn() const { return showAccInfoBtn; }




private:
    void initUi();

private:
    QPushButton* openAccountBtn;
    QPushButton* closeAccountBtn;
    QPushButton* withdrawBtn;
    QPushButton* transferBtn;
    QPushButton* putMoneyBtn;
    QPushButton* showAccInfoBtn;

};

