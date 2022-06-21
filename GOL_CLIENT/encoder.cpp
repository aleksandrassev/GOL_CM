#include "encoder.h"

int Encoder::parseCounter(QString &buffer)
{
    QString counter = "";

    for (int i = buffer.size() - 1; i >= 0; i--)
    {
        if (buffer[i] == '!')
        {
            return counter.toInt();
        }
        counter.insert(0, buffer[i]);
    }
    return counter.toInt();
}

bool Encoder::encode(std::vector<std::vector<bool>> &field, QString &buffer)
{
    if (field.empty())
    {
        return false;
    }
    for (int i = 0; i < field.size(); i++)
    {
        for (int j = 0; j < field[i].size(); j++)
        {
            buffer += QString::number(field[i][j]);
        }
        buffer += "\n";
    }
    return true;
}

bool Encoder::decode(std::vector<std::vector<bool>> &field, QString &buffer)
{
    if (buffer.isEmpty())
    {
        return false;
    }

    field.clear();
    std::vector<bool> line;

    for (auto &i : buffer)
    {
        if (i != '\n')
        {
            line.push_back(i.digitValue());
        }
        else
        {
            field.push_back(line);
            line.clear();
        }
    }
    return true;
}
