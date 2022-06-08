#include "encoder_test.h"


TEST_F(Encoder_test, encode)
{
    Field field(3, 5);
    Field field2(3, 5);
    field2.setCellStatus(2,1, true);
    field2.setCellStatus(1,4, true);

    Encoder encoder;
    QString fstr = encoder.encode(&field);
    QString fstr2 = encoder.encode(&field2);

    ASSERT_TRUE(fstr == "00000\n00000\n00000\n");
    ASSERT_TRUE(fstr2 == "00000\n00001\n01000\n");
    ASSERT_FALSE(fstr == "00000\n00100\n00000\n");
    ASSERT_FALSE(fstr2 == "00000\n00000\n01000\n");
}

TEST_F(Encoder_test, decode)
{
    QString fstr = "00000\n00000\n00000\n";
    QString fstr2 = "00000\n00001\n01000\n";

    Encoder encoder;
    Field field = encoder.decode(fstr);
    Field field2 = encoder.decode(fstr2);

    ASSERT_EQ(field.getRowSize(), 3);
    ASSERT_EQ(field.getColSize(), 5);
    ASSERT_EQ(field.getCellStatus(2,1), false);
    ASSERT_EQ(field2.getCellStatus(2,1), true);
    ASSERT_NE(field.getCellStatus(1,1), true);
    ASSERT_NE(field2.getColSize(), 8);
    ASSERT_NE(field2.getCellStatus(1,4), false);
}

TEST_F(Encoder_test, calculateFieldSize)
{
    QString fstr = "00000\n00000\n00000\n";
    QString fstr2 = "0000\n0001\n0100\n0000\n";

    Encoder encoder;
    auto size_fstr = encoder.calculateFieldSize(fstr);
    auto size_fstr2 = encoder.calculateFieldSize(fstr2);

    ASSERT_EQ(size_fstr.first, 3);
    ASSERT_EQ(size_fstr.second, 5);
    ASSERT_EQ(size_fstr2.first, 4);
    ASSERT_EQ(size_fstr2.second, 4);
    ASSERT_NE(size_fstr.first, 8);
}
