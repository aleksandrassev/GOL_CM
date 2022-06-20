#ifndef FIELD_H
#define FIELD_H

#include <ifield.h>
#include <vector>

class Field : public IField
{
public:
    Field();
    Field(int rows, int cols);
    ~Field() override = default;

    bool getCellStatus(int positionX, int positionY) const override;
    void setCellStatus(int positionX, int positionY, bool status) override;
    int getRowSize() const override;
    int getColSize() const override;

protected:
    std::vector<std::vector<bool>> m_vector;
};

#endif // FIELD_H
