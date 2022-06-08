#include "datahandler.h"

DataHandler::DataHandler()
{
}

int DataHandler::separateCounter(QString &buffer)
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

QString DataHandler::vectorToString(std::vector<std::vector<bool>> &data)
{
    QString dataString;

    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            dataString += QString::number(data[i][j]);
        }
        dataString += "\n";
    }

    return dataString;
}
