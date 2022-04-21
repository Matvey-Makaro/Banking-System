#pragma once

#include "mainView.h"
#include "IBankSystem.h"
#include "chooseBankView.h"

#include <QObject>
#include <QListWidgetItem>

class MainPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MainPresenter(QObject *parent = nullptr);

signals:

private slots:
void getBankNameFromBankingSystem(QListWidgetItem* item);

private:
    MainView* mainView;
    IBankSystem* bankSystem;
    ChooseBankView* chooseBankView;
};

