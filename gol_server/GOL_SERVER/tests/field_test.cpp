#include "field_test.h"
#include <vector>


TEST_F(Field_test, constructor)
{
    ASSERT_NO_THROW(Field field(5, 5));
}

TEST_F(Field_test, get_rows)
{
    Field field(10, 15);

    EXPECT_EQ(field.getRowSize(), 10);
    EXPECT_NE(field.getRowSize(), 15);
}

TEST_F(Field_test, get_cols)
{
    Field field(10, 15);

    EXPECT_EQ(field.getColSize(), 15);
    EXPECT_NE(field.getColSize(), 10);
}

TEST_F(Field_test, get_cell_status)
{
    Field field(10, 15);

    EXPECT_EQ(field.getCellStatus(7, 6), false);
    EXPECT_NE(field.getCellStatus(5, 4), true);
}


TEST_F(Field_test, set_cell_status)
{
    Field field(9, 20);

    field.setCellStatus(8, 7, true);

    EXPECT_EQ(field.getCellStatus(8, 7), true);
    EXPECT_EQ(field.getCellStatus(5, 5), false);
}


