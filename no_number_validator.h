#pragma once

#include <QValidator>
#include <QRegExp>

class NoNumberValidator : public QValidator
{
public:
    explicit NoNumberValidator(QObject* parent = nullptr) : QValidator(parent) {}

    virtual State validate(QString& str, int& pos) const override
    {
        QRegExp rxp = QRegExp("[0-9]");
        if(str.contains(rxp))
            return Invalid;
        return Acceptable;
    }
};
