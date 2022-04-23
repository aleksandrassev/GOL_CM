#ifndef ICYCLE_H
#define ICYCLE_H

#include <QString>

class ICycle
{
public:
    virtual QString nextGeneration() = 0;

protected:
    virtual ~ICycle() = default;
};

#endif // ICYCLE_H
