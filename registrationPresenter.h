#pragma once

#include "IBank.h"
#include "registrationView.h"
#include "user.h"

#include <QObject>
#include <memory>

class RegistrationPresenter : public QObject
{
    Q_OBJECT
public:
    explicit RegistrationPresenter(std::shared_ptr<IBank> bank, QObject *parent = nullptr);

signals:
    void notAllFieldsAreFilled() const;
    void registrationApplicationAccepted() const;

private slots:
    void signUpUser() const;

private:
    bool isAllFieldsFilledIn(const User& user) const;

private:
    std::shared_ptr<IBank> bank;
    std::shared_ptr<RegistrationView> registrationView;

};

