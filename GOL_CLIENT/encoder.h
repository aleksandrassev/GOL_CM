#ifndef ENCODER_H
#define ENCODER_H

#include <QString>
#include <vector>
#include <QDebug>

class Encoder
{
public:
    int parseCounter(QString &buffer);
    bool encode(std::vector<std::vector<bool>> &field, QString &buffer);
    bool decode(std::vector<std::vector<bool>> &field, QString &buffer);
};

#endif // ENCODER_H
