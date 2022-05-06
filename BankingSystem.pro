QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authorization_presenter.cpp \
    authorization_view.cpp \
    bank.cpp \
    bank_system.cpp \
    choose_bank_view.cpp \
    client.cpp \
    client_accounts_view.cpp \
    client_presenter.cpp \
    client_view.cpp \
    database.cpp \
    main.cpp \
    main_presenter.cpp \
    main_view.cpp \
    mainwindow.cpp \
    registration_presenter.cpp \
    registration_view.cpp \
    user.cpp

HEADERS += \
    authorization_presenter.h \
    authorization_view.h \
    bank.h \
    bank_system.h \
    choose_bank_view.h \
    client.h \
    client_accounts_view.h \
    client_presenter.h \
    client_view.h \
    config.h \
    database.h \
    ibank.h \
    ibank_system.h \
    iclient.h \
    ipassword_hasher.h \
    length_validator.h \
    main_presenter.h \
    main_view.h \
    mainwindow.h \
    md5_password_hasher.h \
    no_number_validator.h \
    registration_presenter.h \
    registration_view.h \
    user.h \
    user_type.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
