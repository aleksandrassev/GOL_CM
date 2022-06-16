#ifndef ENCODER_H
#define ENCODER_H

#include "iencoder.h"

class Encoder : public IEncoder
{
public:
    Encoder() = default;
    ~Encoder() override = default;

    QString encode(const IField* field) override;
    Field decode(const QString& str) override;
    std::pair<int, int> parseFieldSize(const QString& str);
};

#endif // ENCODER_H
