#ifndef IENCODER_H
#define IENCODER_H

#include <QString>
#include <ifield.h>
#include <field.h>

class IEncoder
{
public:
    virtual QString encode(const IField* field) = 0;
    virtual bool decode(const QString& str, IField* field) = 0;

protected:
    virtual ~IEncoder() = default;
};

#endif // IENCODER_H
