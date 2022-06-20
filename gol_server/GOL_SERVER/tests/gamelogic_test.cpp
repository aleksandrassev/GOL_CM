#include "gtest/gtest.h"
#include "gamelogic.h"
#include "encoder.h"
#include "rules.h"
#include "QDebug"

class GameLogic_test : public :: testing :: Test
{
public:
    void SetUp() override
    {
        field = new Field(8, 8);
        nextField = new Field(8,8);
        encoder = new Encoder();
        rules = new Rules();
        glogic = new GameLogic (encoder, rules, field, nextField);
    }
    void TearDown() override
    {
        delete glogic;
        glogic = nullptr;

        delete encoder;
        encoder = nullptr;

        delete rules;
        rules = nullptr;

        delete field;
        field = nullptr;

        delete nextField;
        nextField = nullptr;
    }
    Field* field = nullptr;
    Field* nextField = nullptr;
    Encoder* encoder = nullptr;
    Rules* rules = nullptr;
    GameLogic* glogic = nullptr;
};


TEST_F(GameLogic_test, apply_rule)
{
    field->setCellStatus(1,2, true);
    field->setCellStatus(2,3, true);
    field->setCellStatus(3,1, true);
    field->setCellStatus(3,2, true);
    field->setCellStatus(3,3, true);

    glogic->applyRule(3, 2, field, nextField);

    EXPECT_TRUE(nextField->getCellStatus(3, 2));
}

TEST_F(GameLogic_test, find_neighbours_zero)
{
    field->setCellStatus(5, 5, true);
    field->setCellStatus(1, 1, true);
    EXPECT_FALSE(glogic->findNeighbours(5, 5, field));
}

TEST_F(GameLogic_test, find_neighbours_one)
{
    field->setCellStatus(6, 5, true);
    EXPECT_EQ(glogic->findNeighbours(5, 5, field), 1);
}

TEST_F(GameLogic_test, find_neighbours_two)
{
    field->setCellStatus(4, 5, true);
    field->setCellStatus(6, 5, true);
    EXPECT_EQ(glogic->findNeighbours(5, 5, field), 2);
}

TEST_F(GameLogic_test, find_neighbours_three)
{
    field->setCellStatus(4, 4, true);
    field->setCellStatus(4, 5, true);
    field->setCellStatus(6, 5, true);
    EXPECT_EQ(glogic->findNeighbours(5, 5, field), 3);
}

TEST_F(GameLogic_test, find_neighbours_four)
{
    field->setCellStatus(4, 4, true);
    field->setCellStatus(5, 4, true);
    field->setCellStatus(4, 5, true);
    field->setCellStatus(6, 5, true);
    EXPECT_EQ(glogic->findNeighbours(5, 5, field), 4);
}

TEST_F(GameLogic_test, find_neighbours_five)
{
    field->setCellStatus(4, 4, true);
    field->setCellStatus(5, 4, true);
    field->setCellStatus(6, 4, true);
    field->setCellStatus(4, 5, true);
    field->setCellStatus(6, 5, true);
    EXPECT_EQ(glogic->findNeighbours(5, 5, field), 5);
}

TEST_F(GameLogic_test, find_neighbours_six)
{
    field->setCellStatus(4, 4, true);
    field->setCellStatus(5, 4, true);
    field->setCellStatus(6, 4, true);
    field->setCellStatus(4, 5, true);
    field->setCellStatus(6, 5, true);
    field->setCellStatus(6, 6, true);
    EXPECT_EQ(glogic->findNeighbours(5, 5, field), 6);
}

TEST_F(GameLogic_test, find_neighbours_seven)
{
    field->setCellStatus(4, 4, true);
    field->setCellStatus(5, 4, true);
    field->setCellStatus(6, 4, true);
    field->setCellStatus(4, 5, true);
    field->setCellStatus(6, 5, true);
    field->setCellStatus(4, 6, true);
    field->setCellStatus(5, 6, true);
    EXPECT_EQ(glogic->findNeighbours(5, 5, field), 7);
}

TEST_F(GameLogic_test, find_neighbours_eight)
{
    field->setCellStatus(4, 4, true);
    field->setCellStatus(5, 4, true);
    field->setCellStatus(6, 4, true);
    field->setCellStatus(4, 5, true);
    field->setCellStatus(6, 5, true);
    field->setCellStatus(4, 6, true);
    field->setCellStatus(5, 6, true);
    field->setCellStatus(6, 6, true);
    EXPECT_EQ(glogic->findNeighbours(5, 5, field), 8);
}

TEST_F(GameLogic_test, next_generation)
{
    field->setCellStatus(1,2, true);
    field->setCellStatus(2,3, true);
    field->setCellStatus(3,1, true);
    field->setCellStatus(3,2, true);
    field->setCellStatus(3,3, true);

    QString nextFieldString = glogic->nextGeneration();
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

