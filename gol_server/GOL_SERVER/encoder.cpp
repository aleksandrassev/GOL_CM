#include "encoder.h"


QString Encoder::encode(const Field* field)
{
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
    std::vector<std::vector<bool>> field;
    std::vector<bool> fieldLine;

    for (auto &i : fieldAsString)
    {
        if (i != '\n')
        {
            fieldLine.push_back(i.digitValue());
        }
        else
        {
            field.push_back(fieldLine);
            fieldLine.clear();
        }
    }
    return field;
}
