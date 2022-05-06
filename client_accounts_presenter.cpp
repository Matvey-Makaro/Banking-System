#include "client_accounts_presenter.h"

ClientAccountsPresenter::ClientAccountsPresenter(QObject *parent) :
    clientAccountsView(std::make_shared<ClientAccountsView>()) , QObject(parent)
{
    clientAccountsView->show();
}
