#ifndef ENCODER_H
#define ENCODER_H

#include "iencoder.h"

class Encoder : public IEncoder
{
public:
    Encoder() = default;
    ~Encoder() override = default;

    QString encode(const Field* field) override;
    Field decode(const QString& str) override;
};

#endif // ENCODER_H
