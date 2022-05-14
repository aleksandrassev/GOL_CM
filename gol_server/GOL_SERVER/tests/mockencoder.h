#ifndef MOCKENCODER_H
#define MOCKENCODER_H

#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "iencoder.h"
#include <QString>

class MockEncoder: public IEncoder
{
public:
    MOCK_METHOD(QString, encode, (const Field* field), (override));
    MOCK_METHOD(Field, decode, (const QString &str), (override));

};

#endif // MOCKENCODER_H