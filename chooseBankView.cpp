#include "chooseBankView.h"

ChooseBankView::ChooseBankView(const QStringList& bankNames, QWidget *parent) : QWidget(parent)
{
    banks = new QListWidget();
    banks->addItems(bankNames);
    banks->show();
}
