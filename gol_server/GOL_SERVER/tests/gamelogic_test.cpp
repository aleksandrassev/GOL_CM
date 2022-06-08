#include "gamelogic_test.h"

#include "rules.h"
#include "encoder.h"

TEST_F(GameLogic_test, apply_rule)
{
    std::vector<std::vector<bool>> vector(8, std::vector<bool>(8));
    Field field(8, 8);
    Field nextField(8, 8);
    Encoder encoder;
    Rules rules;
    GameLogic glogic(&encoder, &rules, &field, &nextField);

    field.setCellStatus(1,2, true);
    field.setCellStatus(2,3, true);
    field.setCellStatus(3,1, true);
    field.setCellStatus(3,2, true);
    field.setCellStatus(3,3, true);

    ASSERT_FALSE(nextField.getCellStatus(3, 2));

    glogic.applyRule(3, 2, &field, &nextField);

    ASSERT_TRUE(nextField.getCellStatus(3, 2));
}

TEST_F(GameLogic_test, find_neighbours)
{
    std::vector<std::vector<bool>> vector(10, std::vector<bool>(10));
    Field field(10, 10);
    Field nextField(10, 10);
    Encoder encoder;
    Rules rules;
    GameLogic glogic(&encoder, &rules, &field, &nextField);

    field.setCellStatus(5, 5, true);

    EXPECT_TRUE(glogic.findNeighbours(5, 5, &field) == 0);

    field.setCellStatus(4, 5, true);
    field.setCellStatus(6, 5, true);

    EXPECT_FALSE(glogic.findNeighbours(5, 5, &field) == 0);
    EXPECT_FALSE(glogic.findNeighbours(5, 5, &field) == 1);
    EXPECT_TRUE(glogic.findNeighbours(5, 5, &field) == 2);

    field.setCellStatus(4, 4, true);
    field.setCellStatus(6, 6, true);

    EXPECT_TRUE(glogic.findNeighbours(5, 5, &field) == 4);

    field.setCellStatus(1, 1, true);

    EXPECT_TRUE(glogic.findNeighbours(5, 5, &field) == 4);
    EXPECT_TRUE(glogic.findNeighbours(0, 1, &field) == 1);
}

TEST_F(GameLogic_test, next_generation)
{
    std::vector<std::vector<bool>> vector(8, std::vector<bool>(8));
    Field field(8, 8);
    Field nextField(8, 8);
    Encoder encoder;
    Rules rules;
    GameLogic glogic(&encoder, &rules, &field, &nextField);

    field.setCellStatus(1,2, true);
    field.setCellStatus(2,3, true);
    field.setCellStatus(3,1, true);
    field.setCellStatus(3,2, true);
    field.setCellStatus(3,3, true);

    QString nextFieldString = glogic.nextGeneration();
    QString notExpectedString = "00000000\n"
                             "00100000\n"
                             "00010000\n"
                             "01110000\n"
                             "00000000\n"
                             "00000000\n"
                             "00000000\n"
                             "00000000\n";
    QString expectedString = "00000000\n"
                             "00000000\n"
                             "01010000\n"
                             "00110000\n"
                             "00100000\n"
                             "00000000\n"
                             "00000000\n"
                             "00000000\n";

    ASSERT_NE(nextFieldString, notExpectedString);
    ASSERT_EQ(nextFieldString, expectedString);
}

TEST_F(GameLogic_test, isFieldEmpty)
{
    std::vector<std::vector<bool>> vector(10, std::vector<bool>(10));
    Field field(10, 10);
    Field nextField(10, 10);
    Encoder encoder;
    Rules rules;
    GameLogic glogic(&encoder, &rules, &field, &nextField);

    field.setCellStatus(5, 5, true);

    EXPECT_TRUE(glogic.findNeighbours(5, 5, &field) == 0);

    field.setCellStatus(4, 5, true);
    field.setCellStatus(6, 5, true);

    EXPECT_FALSE(glogic.findNeighbours(5, 5, &field) == 0);
    EXPECT_FALSE(glogic.findNeighbours(5, 5, &field) == 1);
    EXPECT_TRUE(glogic.findNeighbours(5, 5, &field) == 2);

    field.setCellStatus(4, 4, true);
    field.setCellStatus(6, 6, true);

    EXPECT_TRUE(glogic.findNeighbours(5, 5, &field) == 4);

    field.setCellStatus(1, 1, true);

    EXPECT_TRUE(glogic.findNeighbours(5, 5, &field) == 4);
    EXPECT_TRUE(glogic.findNeighbours(0, 1, &field) == 1);
}
