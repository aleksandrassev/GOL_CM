#ifndef FIELD_H
#define FIELD_H

#include <ifield.h>
#include <vector>

class Field : public IField
{
public:
    Field(int rows, int cols);
    ~Field() override = default;

    bool getCellStatus(int positionX, int positionY) const override;
    virtual void setCellStatus(int positionX, int positionY, bool status) override;
    virtual int findNeighbours(int positionX, int positionY) const override;
    int getRowSize() const;
    int getColSize() const;

protected:
    std::vector<std::vector<bool>> m_2Dvector;
};

#endif // FIELD_H
