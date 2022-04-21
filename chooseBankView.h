#pragma once

#include <QWidget>
#include <QListWidget>
#include <QStringList>

class ChooseBankView : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseBankView(const QStringList& bankNames, QWidget *parent = nullptr);
    const QListWidget* getBanksNameListWidget();
signals:

private:


private:
    QListWidget* banks;

};

