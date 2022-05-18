#pragma once

#include "client_deposits_view.h"
#include "iclient.h"

#include <QObject>
#include <memory>

class ClientDepositsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit ClientDepositsPresenter(std::shared_ptr<IClient> client, QObject *parent = nullptr);
    QSqlQueryModel& getDepositsQueryModel() const;

signals:
    void showAccountInfo(QString accountInfo) const;
    void errorHappened(QString error) const;

private slots:
    void showDepositInfo();
    void openDeposit();
    void withdrawMoney();

private:
    std::shared_ptr<IClient> client;
    std::shared_ptr<ClientDepositsView> clientDepositsView;

};

