#include "mainwindow.h"
#include "database.h"
#include "mainPresenter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database::getInstance();
    MainPresenter mainPresenter;






//    MainWindow w;
//    w.show();
    return a.exec();
}
