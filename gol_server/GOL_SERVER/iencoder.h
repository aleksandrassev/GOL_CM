#ifndef IENCODER_H
#define IENCODER_H

#include <QString>
#include <ifield.h>
#include <field.h>

class IEncoder
{
public:
    virtual QString encode(const IField* field) = 0;
    virtual Field decode(const QString& str) = 0;

protected:
    virtual ~IEncoder() = default;
};

#endif // IENCODER_H
