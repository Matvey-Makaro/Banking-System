#include "mainwindow.h"
#include "database.h"
#include "main_presenter.h"

#include "md5_password_hasher.h" //TODO: Удалить потом

#include <QApplication>

//DEBUG
#include <QtWidgets>
#include <QSqlQueryModel>
#include <QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Database::getInstance();

    MD5PasswordHasher hasher;
    qDebug() << "Hash: " << hasher.hash("123") << '\n';

//    QTableView view;
//    QSqlQueryModel model;
//    QString str = "SELECT * FROM BelarusBankClients;";
//    model.setQuery(str);
//    if(model.lastError().isValid())
//        qDebug() << model.lastError() << "\n";
//    model.setHeaderData(0, Qt::Horizontal, "Идентификационный номер");
//    view.setModel(&model);
//    view.show();
//    qDebug() << view.currentIndex().row() << "\n";


    MainPresenter mainPresenter;






//    MainWindow w;
//    w.show();
    return a.exec();
}
