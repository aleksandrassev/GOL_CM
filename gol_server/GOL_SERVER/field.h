#ifndef FIELD_H
#define FIELD_H

#include <ifield.h>
#include <vector>

class Field : public IField
{
public:
    Field(std::vector<std::vector<bool>> &vector);
    ~Field() override = default;

    bool getCellStatus(int positionX, int positionY) const override;
    virtual void setCellStatus(int positionX, int positionY, bool status) override;
    virtual int findNeighbours(int positionX, int positionY) const override;
    int getRowSize() const;
    int getColSize() const;

protected:
    std::vector<std::vector<bool>> m_vector;
};

#endif // FIELD_H
