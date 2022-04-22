#include "encoder_test.h"


TEST_F(Encoder_test, encode)
{
    std::vector<std::vector<bool>> vector(3, std::vector<bool>(5));
    Field field(vector);
    Field field2(vector);
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
