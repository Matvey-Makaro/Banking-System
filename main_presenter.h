#pragma once

#include "main_view.h"
#include "ibank_system.h"
#include "choose_bank_view.h"
#include "authorization_presenter.h"
#include "ibank.h"

#include <QObject>
#include <QListWidgetItem>
#include <memory>

class MainPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MainPresenter(QObject *parent = nullptr);
    ~MainPresenter() = default;

signals:

private slots:
    void goToAuthorization(QListWidgetItem* chosenBank);


private:
    void getBank();
    void getBankName(QListWidgetItem* item);
    void passContorlToAuthorizationPresenter();

private:
    std::shared_ptr<IBankSystem> bankSystem;
    std::shared_ptr<ChooseBankView> chooseBankView;
    std::shared_ptr<MainView> mainView;
    std::shared_ptr<AuthorizationPresenter> authorizationPresenter;
    QString bankName;
    std::shared_ptr<IBank> bank;
};

