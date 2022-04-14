#pragma once

#include "mainView.h"
#include "IBankSystem.h"
#include "chooseBankView.h"

#include <QObject>

class MainPresenter : public QObject
{
    Q_OBJECT
public:
    explicit MainPresenter(QObject *parent = nullptr);

signals:

private slots:


private:
    MainView* mainView;
    IBankSystem* bankSystem;
    ChooseBankView* chooseBankView;
};

