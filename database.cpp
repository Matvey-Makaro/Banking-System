#include "database.h"

#include <QDebug>
#include <QSqlError>
#include <stdexcept>


bool Database::isConnected = false;

QSqlDatabase& Database::getInstance()
{
    if(isConnected == false)
        createConnection();
    return instance;
}

bool Database::isOpen() { return isConnected; }

void Database::createConnection()
{
    instance = QSqlDatabase::addDatabase(databaseType);
    instance.setDatabaseName(databaseName);
    instance.setUserName(databaseUserName);
    if(!instance.open())
    {
       qDebug() << "Cannot open database:" << instance.lastError() << '\n';
       throw std::runtime_error(instance.lastError().text().toStdString());
    }
    isConnected = true;
}
