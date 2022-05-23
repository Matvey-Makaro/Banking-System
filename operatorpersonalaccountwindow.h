#ifndef OPERATORPERSONALACCOUNTWINDOW_H
#define OPERATORPERSONALACCOUNTWINDOW_H

#include "operator.h"

#include <QDialog>
#include <ibanksystemmodel.h>
#include <QtWidgets>

class OperatorPersonalAccountWindow : public QDialog
{
    Q_OBJECT
public:
    OperatorPersonalAccountWindow(IBankSystemModel *bankSystem, QWidget* parent = nullptr);
    void setCurrentOperatorData(Operator* op);

private:
    IBankSystemModel* bankSystemModel;
    QTableWidget *infoTable;
    Operator* oper = nullptr;
};

#endif // OPERATORPERSONALACCOUNTWINDOW_H
