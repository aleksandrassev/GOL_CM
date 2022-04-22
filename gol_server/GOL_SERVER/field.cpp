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

int Field::findNeighbours(int row, int col) const
{
    int alive_neib = 0;
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int row_mod = (row + i + getRowSize()) % getRowSize();
            int col_mod = (col + j + getColSize()) % getColSize();

            if (m_vector[row_mod][col_mod])
            {
                alive_neib++;
            }
        }
    }
    return (alive_neib - m_vector[row][col]);
}

int Field::getRowSize() const
{
    return static_cast<int>(m_vector.size());
}

int Field::getColSize() const
{
    return static_cast<int>(m_vector[0].size());
}
