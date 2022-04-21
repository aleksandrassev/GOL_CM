#include "field_test.h"


TEST_F(Field_test, constructor_values)
{
    ASSERT_NO_THROW(Field field(7, 6));
}

TEST_F(Field_test, constructor_negative_values)
{
    ASSERT_THROW(Field field(-11, 6), std::length_error);
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

    EXPECT_NE(field.getCellStatus(8, 7), false);
    EXPECT_EQ(field.getCellStatus(8, 7), true);
    EXPECT_EQ(field.getCellStatus(5, 5), false);
}

TEST_F(Field_test, find_neighbours)
{
    Field field(10, 10);
    field.setCellStatus(5, 5, true);

    EXPECT_TRUE(field.findNeighbours(5, 5) == 0);

    field.setCellStatus(4, 5, true);
    field.setCellStatus(6, 5, true);

    EXPECT_FALSE(field.findNeighbours(5, 5) == 0);
    EXPECT_FALSE(field.findNeighbours(5, 5) == 1);
    EXPECT_TRUE(field.findNeighbours(5, 5) == 2);

    field.setCellStatus(4, 4, true);
    field.setCellStatus(6, 6, true);

    EXPECT_TRUE(field.findNeighbours(5, 5) == 4);

    field.setCellStatus(1, 1, true);

    EXPECT_TRUE(field.findNeighbours(5, 5) == 4);
    EXPECT_TRUE(field.findNeighbours(0, 1) == 1);
}
