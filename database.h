#pragma once

#include "config.h"

#include <QSqlDatabase>

class Database
{
public:
    static QSqlDatabase& getInstance();
    static bool isOpen();
private:
    Database() = delete;
    static void createConnection();

private:
    static QSqlDatabase instance;
    static bool isConnected;
};

