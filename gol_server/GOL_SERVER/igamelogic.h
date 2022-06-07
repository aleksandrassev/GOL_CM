#ifndef ICYCLE_H
#define ICYCLE_H

#include <QString>
#include "field.h"


class IGameLogic
{
public:
    virtual QString nextGeneration() = 0;
    virtual int findNeighbours(int positionX, int positionY, IField* field) const = 0;

protected:
    virtual ~IGameLogic() = default;
};

#endif // ICYCLE_H
