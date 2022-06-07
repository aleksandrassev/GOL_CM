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


