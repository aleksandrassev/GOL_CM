#include "gtest/gtest.h"
#include "rules.h"
#include <QDebug>

class Rules_test: public:: testing:: Test
{
};

TEST_F(Rules_test, First_rule)
{
    bool statusAlive = true;
    bool statusDead = false;
    int neighbours_0 = 0;
    int neighbours_1 = 1;
    int neighbours_2 = 2;
    int neighbours_3 = 3;
    int neighbours_7 = 7;

    Rules rules;

    EXPECT_TRUE(rules.executeFirstRule(statusAlive, neighbours_0));
    EXPECT_TRUE(rules.executeFirstRule(statusAlive, neighbours_1));
    EXPECT_FALSE(rules.executeFirstRule(statusAlive, neighbours_2));
    EXPECT_FALSE(rules.executeFirstRule(statusAlive, neighbours_3));
    EXPECT_FALSE(rules.executeFirstRule(statusAlive, neighbours_7));
    EXPECT_FALSE(rules.executeFirstRule(statusDead, neighbours_0));
    EXPECT_FALSE(rules.executeFirstRule(statusDead, neighbours_1));
    EXPECT_FALSE(rules.executeFirstRule(statusDead, neighbours_2));
    EXPECT_FALSE(rules.executeFirstRule(statusDead, neighbours_3));
    EXPECT_FALSE(rules.executeFirstRule(statusDead, neighbours_7));
}

TEST_F(Rules_test, Second_rule)
{
    bool statusAlive = true;
    bool statusDead = false;
    int neighbours_0 = 0;
    int neighbours_1 = 1;
    int neighbours_2 = 2;
    int neighbours_3 = 3;
    int neighbours_7 = 7;

    Rules rules;

    EXPECT_FALSE(rules.executeSecondRule(statusAlive, neighbours_0));
    EXPECT_FALSE(rules.executeSecondRule(statusAlive, neighbours_1));
    EXPECT_FALSE(rules.executeSecondRule(statusAlive, neighbours_2));
    EXPECT_FALSE(rules.executeSecondRule(statusAlive, neighbours_3));
    EXPECT_TRUE(rules.executeSecondRule(statusAlive, neighbours_7));
    EXPECT_FALSE(rules.executeSecondRule(statusDead, neighbours_0));
    EXPECT_FALSE(rules.executeSecondRule(statusDead, neighbours_1));
    EXPECT_FALSE(rules.executeSecondRule(statusDead, neighbours_2));
    EXPECT_FALSE(rules.executeSecondRule(statusDead, neighbours_3));
    EXPECT_FALSE(rules.executeSecondRule(statusDead, neighbours_7));
}

TEST_F(Rules_test, Third_rule)
{
    bool statusAlive = true;
    bool statusDead = false;
    int neighbours_0 = 0;
    int neighbours_1 = 1;
    int neighbours_2 = 2;
    int neighbours_3 = 3;
    int neighbours_7 = 7;

    Rules rules;

    EXPECT_FALSE(rules.executeThirdRule(statusAlive, neighbours_0));
    EXPECT_FALSE(rules.executeThirdRule(statusAlive, neighbours_1));
    EXPECT_FALSE(rules.executeThirdRule(statusAlive, neighbours_2));
    EXPECT_FALSE(rules.executeThirdRule(statusAlive, neighbours_3));
    EXPECT_FALSE(rules.executeThirdRule(statusAlive, neighbours_7));
    EXPECT_FALSE(rules.executeThirdRule(statusDead, neighbours_0));
    EXPECT_FALSE(rules.executeThirdRule(statusDead, neighbours_1));
    EXPECT_FALSE(rules.executeThirdRule(statusDead, neighbours_2));
    EXPECT_TRUE(rules.executeThirdRule(statusDead, neighbours_3));
    EXPECT_FALSE(rules.executeThirdRule(statusDead, neighbours_7));
}

TEST_F(Rules_test, Fourth_rule)
{
    bool statusAlive = true;
    bool statusDead = false;
    int neighbours_0 = 0;
    int neighbours_1 = 1;
    int neighbours_2 = 2;
    int neighbours_3 = 3;
    int neighbours_7 = 7;

    Rules rules;

    EXPECT_FALSE(rules.executeFourthRule(statusAlive, neighbours_0));
    EXPECT_FALSE(rules.executeFourthRule(statusAlive, neighbours_1));
    EXPECT_TRUE(rules.executeFourthRule(statusAlive, neighbours_2));
    EXPECT_TRUE(rules.executeFourthRule(statusAlive, neighbours_3));
    EXPECT_FALSE(rules.executeFourthRule(statusAlive, neighbours_7));
    EXPECT_FALSE(rules.executeFourthRule(statusDead, neighbours_0));
    EXPECT_FALSE(rules.executeFourthRule(statusDead, neighbours_1));
    EXPECT_FALSE(rules.executeFourthRule(statusDead, neighbours_2));
    EXPECT_FALSE(rules.executeFourthRule(statusDead, neighbours_3));
    EXPECT_FALSE(rules.executeFourthRule(statusDead, neighbours_7));
}
