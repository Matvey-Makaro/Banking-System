#pragma once

#include <QValidator>
#include <QString>

class LengthValidator : public QValidator
{
public:
    LengthValidator(size_t maxLength, size_t minLength = 0, QObject* parent = nullptr) :
        QValidator(parent), maxLength(maxLength), minLength(minLength)
    {}

    void setMaxLength(size_t newLength) { maxLength = newLength; }
    size_t getMaxLength() { return maxLength; }
    void setMinLength(size_t newLength) { minLength = newLength; }
    size_t getMinLength() { return minLength; }

    virtual State validate(QString& str, int& pos) const override
    {
        if(str.size() < minLength)
            return Intermediate;
        if(str.size() > maxLength)
            return Invalid;
        return Acceptable;
    }

private:
    size_t maxLength;
    size_t minLength;
};
