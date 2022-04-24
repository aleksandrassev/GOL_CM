#ifndef ICYCLE_H
#define ICYCLE_H

#include <QString>
#include "field.h"


class ICycle
{
public:
    virtual QString nextGeneration(Field* field) = 0;

protected:
    virtual ~ICycle() = default;
};

#endif // ICYCLE_H
