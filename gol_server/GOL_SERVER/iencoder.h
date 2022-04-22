#ifndef IENCODER_H
#define IENCODER_H

#include <QString>
#include <field.h>

class IEncoder
{
    virtual QString encode(const Field* field) = 0;
    virtual Field decode(const QString& str) = 0;

protected:
    virtual ~IEncoder() = default;
};

#endif // IENCODER_H
