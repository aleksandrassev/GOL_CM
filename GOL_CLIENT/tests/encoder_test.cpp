#include "gtest/gtest.h"
#include "encoder.h"
#include <QDebug>

class Encoder_test: public:: testing:: Test
{
};

TEST_F(Encoder_test, parse)
{
    Encoder encoder;
    QString fstr1 = "00000\n00000!5";
    QString fstr2 = "00000\n00011201\nfdgdfg\n!8";

    EXPECT_EQ(encoder.parseCounter(fstr1), 5);
    EXPECT_EQ(encoder.parseCounter(fstr2), 8);
}

TEST_F(Encoder_test, encode)
{
    std::vector<std::vector<bool>> field (3, std::vector<bool>(5, false));
    std::vector<std::vector<bool>> emptyField;
    QString buffer = "";

    Encoder encoder;
    bool isEncodedField = encoder.encode(field, buffer);
    bool isEncodedEmptyField = encoder.encode(emptyField, buffer);

    EXPECT_TRUE(isEncodedField);
    EXPECT_FALSE(isEncodedEmptyField);
    EXPECT_EQ(buffer, "00000\n00000\n00000\n");
}

TEST_F(Encoder_test, decode)
{
    QString buffer = "00000\n00010\n01000\n";
    QString emptyBuffer = "";
    std::vector<std::vector<bool>> emptyField;
    std::vector<std::vector<bool>> field (1, std::vector<bool>(7, false));

    Encoder encoder;
    bool isDecodedEmptyBuffer = encoder.decode(emptyField, emptyBuffer);
    bool isDecodedBuffer = encoder.decode(emptyField, buffer);
    bool isDecodedAnother = encoder.decode(field, buffer);

    EXPECT_FALSE(isDecodedEmptyBuffer);
    EXPECT_TRUE(isDecodedBuffer);
    EXPECT_TRUE(isDecodedAnother);
    EXPECT_FALSE(emptyField.empty());
    EXPECT_TRUE(field[1][3]);
    EXPECT_EQ(field.size(), 3);
    EXPECT_EQ(field[0].size(), 5);
}
