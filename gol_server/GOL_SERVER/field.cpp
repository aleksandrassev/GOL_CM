#include "field.h"

Field::Field(int rows, int cols)
    :m_2Dvector(std::vector<std::vector<bool>>(rows, std::vector<bool>(cols)))
{
}

bool Field::getCellStatus(int row, int col) const
{
    return m_2Dvector[row][col];
}

void Field::setCellStatus(int row, int col, bool status)
{
    m_2Dvector[row][col] = status;
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

            if (m_2Dvector[row_mod][col_mod])
            {
                alive_neib++;
            }
        }
    }
    return (alive_neib - m_2Dvector[row][col]);
}

int Field::getRowSize() const
{
    return static_cast<int>(m_2Dvector.size());
}

int Field::getColSize() const
{
    return static_cast<int>(m_2Dvector[0].size());
}
