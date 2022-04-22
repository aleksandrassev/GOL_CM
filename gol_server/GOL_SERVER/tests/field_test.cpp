#include "field_test.h"
#include <vector>


TEST_F(Field_test, constructor)
{
    std::vector<std::vector<bool>> vector{{0,0}, {0,0}, {0,0}, {0,0}};

    ASSERT_NO_THROW(Field field(vector));
}

TEST_F(Field_test, get_rows)
{
    std::vector<std::vector<bool>> vector(10, std::vector<bool>(15));
    Field field(vector);

    EXPECT_EQ(field.getRowSize(), 10);
    EXPECT_NE(field.getRowSize(), 15);
}

TEST_F(Field_test, get_cols)
{
    std::vector<std::vector<bool>> vector(10, std::vector<bool>(15));
    Field field(vector);

    EXPECT_EQ(field.getColSize(), 15);
    EXPECT_NE(field.getColSize(), 10);
}

TEST_F(Field_test, get_cell_status)
{
    std::vector<std::vector<bool>> vector(10, std::vector<bool>(15));
    Field field(vector);

    EXPECT_EQ(field.getCellStatus(7, 6), false);
    EXPECT_NE(field.getCellStatus(5, 4), true);
}


TEST_F(Field_test, set_cell_status)
{
    std::vector<std::vector<bool>> vector(9, std::vector<bool>(20));
    Field field(vector);

    field.setCellStatus(8, 7, true);

    EXPECT_NE(field.getCellStatus(8, 7), false);
    EXPECT_EQ(field.getCellStatus(8, 7), true);
    EXPECT_EQ(field.getCellStatus(5, 5), false);
}

TEST_F(Field_test, find_neighbours)
{
    std::vector<std::vector<bool>> vector(10, std::vector<bool>(10));
    Field field(vector);

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
