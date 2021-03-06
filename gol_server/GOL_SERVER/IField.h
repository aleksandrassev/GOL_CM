#ifndef IFIELD_H
#define IFIELD_H

#include <QString>

class IField
{
public:
    virtual bool getCellStatus(int positionX, int positionY) const = 0;
    virtual void setCellStatus(int positionX, int positionY, bool status) = 0;
    virtual int getRowSize() const = 0;
    virtual int getColSize() const = 0;

    virtual ~IField() = default;
};

#endif // IFIELD_H
