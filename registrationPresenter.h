#pragma once

#include "IBank.h"
#include "registrationView.h"

#include <QObject>
#include <memory>

class RegistrationPresenter : public QObject
{
    Q_OBJECT
public:
    explicit RegistrationPresenter(std::shared_ptr<IBank> bank, QObject *parent = nullptr);

signals:


private:
    std::shared_ptr<IBank> bank;
    std::shared_ptr<RegistrationView> registrationView;
};

