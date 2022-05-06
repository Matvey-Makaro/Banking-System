#pragma once

#include <IClient.h>
#include <clientView.h>

#include <QObject>
#include <memory>

class ClientPresenter : public QObject
{
    Q_OBJECT
public:
    explicit ClientPresenter(std::shared_ptr<IClient> client, QObject *parent = nullptr);
    int getId() const { return client->getId(); }
    const QString& getName() const { return client->getName(); }
    const QString& getSurname() const { return client->getSurname(); }
    const QString& getPatronymic() const { return client->getPatronymic(); }
    const QString& getPhoneNumber() const { return client->getPhoneNumber(); }
    const QString& getEmail() const { return client->getEmail(); }
    const QString& getPassport() const { return client->getPassport(); }
    bool isFromRB() const { return client->isFromRB(); }


private slots:
    void goToClientAccounts();
    void goToClientDeposits();
    void goToClientCredits();
    void goToClientInstallments();
    void goToSalaryProject();


private:
    std::shared_ptr<IClient> client;
    std::shared_ptr<ClientView> clientView;

};

