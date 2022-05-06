#include "mainwindow.h"
#include "database.h"
#include "mainPresenter.h"

#include "md5PasswordHasher.h" //TODO: Удалить потом

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MD5PasswordHasher hasher;
    qDebug() << "Hash: " << hasher.hash("123") << '\n';

    Database::getInstance();
    MainPresenter mainPresenter;






//    MainWindow w;
//    w.show();
    return a.exec();
}
