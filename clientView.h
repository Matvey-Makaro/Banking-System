#pragma once

#include <QWidget>

class ClientPresenter;

class ClientView : public QWidget
{
    Q_OBJECT
public:
    explicit ClientView(ClientPresenter* clientPresenter, QWidget *parent = nullptr);


private:
    void initUI();

private:
    ClientPresenter* clientPresenter;

};

