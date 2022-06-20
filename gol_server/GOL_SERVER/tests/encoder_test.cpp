#include "gtest/gtest.h"
#include "encoder.h"
#include <QDebug>

class Encoder_test: public:: testing:: Test
{
};

TEST_F(Encoder_test, encode)
{
    Field field(3, 5);
    Field field2(3, 5);
    field2.setCellStatus(2,1, true);
    field2.setCellStatus(1,4, true);

    Encoder encoder;
    QString fstr = encoder.encode(&field);
    QString fstr2 = encoder.encode(&field2);

    EXPECT_EQ(fstr.toStdString(), "00000\n00000\n00000\n");
    EXPECT_EQ(fstr2.toStdString(), "00000\n00001\n01000\n");
    EXPECT_NE(fstr.toStdString(), "00000\n00100\n00000\n");
    EXPECT_NE(fstr2.toStdString(), "00000\n00000\n01000\n");
}

TEST_F(Encoder_test, decode)
{
    QString fstr = "00000\n00000\n01000\n";
    QString fstr2 = "00000\n00010\n01000\n";

    Encoder encoder;
    Field* field = new Field(3, 5);
    Field* field2 = new Field(3, 5);
    encoder.decode(fstr, field);
    encoder.decode(fstr2, field2);

    EXPECT_EQ(field->getRowSize(), 3);
    EXPECT_EQ(field->getColSize(), 5);
    EXPECT_TRUE(field->getCellStatus(2,1));
    EXPECT_TRUE(field2->getCellStatus(2,1));
    EXPECT_FALSE(field->getCellStatus(1,1));
    EXPECT_NE(field2->getColSize(), 8);
    EXPECT_FALSE(field2->getCellStatus(1,4));
}

TEST_F(Encoder_test, calculateFieldSize)
{
    QString fstr = "00000\n00000\n00000\n";
    QString fstr2 = "0000\n0001\n0100\n0000\n";

    Encoder encoder;
    auto size_fstr = encoder.parseFieldSize(fstr);
    auto size_fstr2 = encoder.parseFieldSize(fstr2);

    EXPECT_EQ(size_fstr.first, 3);
    EXPECT_EQ(size_fstr.second, 5);
    EXPECT_EQ(size_fstr2.first, 4);
    EXPECT_EQ(size_fstr2.second, 4);
    EXPECT_NE(size_fstr.first, 8);
}
