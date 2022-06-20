#include "encoder.h"
#include <QDebug>


QString Encoder::encode(const IField* field)
{
    if (field == nullptr)
    {
      qCritical("missing field pointer Encoder::encode");
      return "";
    }

    QString fieldAsString;

    int row_size = field->getRowSize();
    int col_size = field->getColSize();

    for (int i = 0; i < row_size; i++)
    {
        for (int j = 0; j < col_size; j++)
        {
            fieldAsString += QString::number(field->getCellStatus(i, j));
        }
        fieldAsString += "\n";
    }
    return fieldAsString;
}

bool Encoder::decode(const QString& fieldAsString, IField* field)
{
    auto fieldSize = parseFieldSize(fieldAsString);
    if (fieldSize.first == 0 || fieldSize.second == 0)
    {
      qCritical("zero size field in Encoder::decode");
      return false;
    }
    if (fieldSize.first != 50 || fieldSize.second != 80)
    {
      qCritical("warning: not default size field in Encoder::decode");
    }

    int row = 0;
    int col = 0;
    for (auto &i : fieldAsString)
    {
        if (i == '!')
        {
            return true;
        }

        if (i != '\n')
        {
            field->setCellStatus(row, col, i.digitValue());
            col++;
        }
        else
        {
            row++;
            col = 0;
        }
    }
    return true;
}

std::pair<int, int> Encoder::parseFieldSize(const QString& str)
{
    int row_nr = 0;
    int col_nr = 0;
    for (auto &i : str)
    {
        if (i != '\n')
        {
            col_nr++;
        }
        else
        {
            row_nr++;
        }
    }
   if ((col_nr != 0) && (row_nr != 0))
   {
       col_nr = col_nr / row_nr;
       return std::make_pair(row_nr, col_nr);
   }
   else
   {
       return std::make_pair(0, 0);
   }
}
