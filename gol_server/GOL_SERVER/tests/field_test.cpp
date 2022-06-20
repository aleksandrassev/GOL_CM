#include <vector>
#include "gtest/gtest.h"
#include "field.h"
#include <QDebug>

class Field_test: public:: testing:: Test
{
};

TEST_F(Field_test, constructor)
{
    ASSERT_NO_THROW(Field field(5, 5));
}

TEST_F(Field_test, get_rows)
{
    Field field(10, 15);

    EXPECT_EQ(field.getRowSize(), 10);
}

TEST_F(Field_test, get_cols)
{
    Field field(10, 15);

    EXPECT_EQ(field.getColSize(), 15);
}

TEST_F(Field_test, get_cell_status)
{
    Field field(10, 15);

    EXPECT_EQ(field.getCellStatus(7, 6), false);
}


TEST_F(Field_test, set_cell_status)
{
    Field field(9, 20);

    field.setCellStatus(8, 7, true);

    EXPECT_EQ(field.getCellStatus(8, 7), true);
}


