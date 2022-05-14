#include "encoder.h"
#include <QDebug>


QString Encoder::encode(const IField* field)
{
    if (field == nullptr)
    {
      qCritical("missing field pointer - Encoder");
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
    std::vector<std::vector<bool>> vectorField;
    std::vector<bool> fieldLine;

    for (auto &i : fieldAsString)
    {
        if (i != '\n')
        {
            fieldLine.push_back(i.digitValue());
        }
        else
        {
            vectorField.push_back(fieldLine);
            fieldLine.clear();
        }
    }
    return vectorField;
}
