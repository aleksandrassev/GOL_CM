#ifndef MOCKENCODER_H
#define MOCKENCODER_H

#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "iencoder.h"
#include <QString>

class MockEncoder: public IEncoder
{
public:
    MOCK_METHOD(QString, encode, (const IField* field), (override));
    MOCK_METHOD(bool, decode, (const QString &str, IField* field), (override));
};

#endif // MOCKENCODER_H
