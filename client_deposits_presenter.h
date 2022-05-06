#pragma once

#include "client_deposits_view.h"

#include <QObject>
#include <memory>

class ClientDepositsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit ClientDepositsPresenter(QObject *parent = nullptr);

private slots:
    void showDepositInfo();
    void openDeposit();
    void withdrawMoney();

private:
    std::shared_ptr<ClientDepositsView> clientDepositsView;

};

