#pragma once

#include "client_accounts_view.h"

#include <QObject>
#include <memory>

class ClientAccountsPresenter : public QObject
{
    Q_OBJECT
public:
    explicit ClientAccountsPresenter(QObject *parent = nullptr);


private:
    std::shared_ptr<ClientAccountsView> clientAccountsView;
};

