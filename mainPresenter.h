#pragma once

#include "mainView.h"
#include "IBankSystem.h"
#include "chooseBankView.h"
#include "authorizationPresenter.h"
#include "IBank.h"

#include <QObject>
#include <QListWidgetItem>

class MainPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MainPresenter(QObject *parent = nullptr);
    ~MainPresenter();

signals:

private slots:
    void goToAuthorization(QListWidgetItem* chosenBank);


private:
    void getBank();
    void getBankName(QListWidgetItem* item);
    void passContorlToAuthorizationPresenter();

private:
    IBankSystem* bankSystem;
    ChooseBankView* chooseBankView;
    MainView* mainView;
    AuthorizationPresenter* authorizationPresenter;
    QString bankName;
    IBank* bank;
};

