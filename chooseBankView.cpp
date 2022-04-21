#include "chooseBankView.h"

#include <QDebug>

ChooseBankView::ChooseBankView(const QStringList& bankNames, QWidget *parent) : QWidget(parent)
{
    initUI(bankNames);
}


const QListWidget* ChooseBankView::getBanksNameListWidget() { return banks; }


ChooseBankView::~ChooseBankView()
{
    delete vbox;
}


void ChooseBankView::initUI(const QStringList& bankNames)
{
    vbox = new QVBoxLayout();
    banks = new QListWidget();
    banks->addItems(bankNames);
    //vbox->addStretch();
    vbox->addWidget(banks);
    //vbox->addStretch();
    //vbox->setAlignment(banks, Qt::AlignVCenter);
    //vbox->setAlignment(banks, Qt::AlignHCenter);
    setLayout(vbox);
    setMinimumWidth(640);
    setMinimumHeight(480);
}
