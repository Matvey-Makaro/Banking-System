#pragma once

#include <authorization_view.h>

#include <QWidget>
#include <memory>

class MainView : public QWidget
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = nullptr);

signals:

private:
    void initUi();

private:
    std::shared_ptr<AuthorizationView> authorizationView;


};

