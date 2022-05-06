#include "clientPresenter.h"

ClientPresenter::ClientPresenter(std::shared_ptr<IClient> client, QObject *parent) :
    client(client), clientView(std::make_shared<ClientView>(this)), QObject(parent)
{
    clientView->show();
}
