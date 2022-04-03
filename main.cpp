#include "mainwindow.h"
#include "authorization_view.h"
#include "authorization_controller.h"
#include "authorization_model.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AuthorizationView view;
    AuthorizationModel model;

    AuthorizationController controller(view, model);


//    MainWindow w;
//    w.show();
    return a.exec();
}
