#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QString>
#include <QDebug>

class DataHandler
{
public:
    DataHandler();

    int separateCounter(QString &buffer);
    QString vectorToString(std::vector<std::vector<bool>> &data);
};

#endif // DATAHANDLER_H
