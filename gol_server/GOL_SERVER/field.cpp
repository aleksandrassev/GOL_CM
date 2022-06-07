#include "field.h"

Field::Field(std::vector<std::vector<bool>>& vector)
{
    m_vector = vector;
}

bool Field::getCellStatus(int row, int col) const
{
    return m_vector[row][col];
}

void Field::setCellStatus(int row, int col, bool status)
{
    m_vector[row][col] = status;
}

int Field::getRowSize() const
{
    return static_cast<int>(m_vector.size());
}

int Field::getColSize() const
{
    return static_cast<int>(m_vector[0].size());
}
