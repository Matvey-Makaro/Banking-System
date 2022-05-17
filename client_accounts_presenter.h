#pragma once

#include <iclient.h>
#include "client_accounts_view.h"
#include "account.h"

#include <QObject>
#include <QtWidgets>
#include <memory>
#include <QSqlQueryModel>

class ClientAccountsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit ClientAccountsPresenter(std::shared_ptr<IClient> client, QObject *parent = nullptr);
    QSqlQueryModel& getAccountsQueryModel() const;

signals:
    void showAccountInfo(QString accountInfo) const;
    void errorHappened(QString error) const;

private slots:
    void openAccount();
    void closeAccount();
    void showAccountInfo();
    void putMoney();
    void withdrawMoney();
    void transferMoney();

private:
    std::shared_ptr<IClient> client;
    std::shared_ptr<ClientAccountsView> clientAccountsView;
};

