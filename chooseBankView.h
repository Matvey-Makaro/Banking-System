#pragma once

#include <QWidget>
#include <QListWidget>
#include <QStringList>
#include <QVBoxLayout>

class ChooseBankView : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseBankView(const QStringList& bankNames, QWidget *parent = nullptr);
    const QListWidget* getBanksNameListWidget();
    ~ChooseBankView();
signals:

private:
    void initUI(const QStringList& bankNames);

private:
    QVBoxLayout* vbox;
    QListWidget* banks;

};

