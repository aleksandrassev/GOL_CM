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

Field Encoder::decode(const QString& fieldAsString)
{
    auto fieldSize = parseFieldSize(fieldAsString);
    Field field (fieldSize.first, fieldSize.second);

    if (fieldSize.first == 0 || fieldSize.second == 0)
    {
      qCritical("zero size field in Encoder::decode");
      return field;
    }
    int row = 0;
    int col = 0;
    for (auto &i : fieldAsString)
    {
        if (i != '\n')
        {
            field.setCellStatus(row, col, i.digitValue());
            col++;
        }
        else
        {
            row++;
            col = 0;
        }
    }
    return field;
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
