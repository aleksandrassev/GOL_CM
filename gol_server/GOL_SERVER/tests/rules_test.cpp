#include "rules_test.h"

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
    bool result_1 = rules.executeFirstRule(statusAlive, neighbours_0);
    bool result_2 = rules.executeFirstRule(statusAlive, neighbours_1);
    bool result_3 = rules.executeFirstRule(statusAlive, neighbours_2);
    bool result_4 = rules.executeFirstRule(statusAlive, neighbours_3);
    bool result_5 = rules.executeFirstRule(statusAlive, neighbours_7);
    bool result_6 = rules.executeFirstRule(statusDead, neighbours_0);
    bool result_7 = rules.executeFirstRule(statusDead, neighbours_1);
    bool result_8 = rules.executeFirstRule(statusDead, neighbours_2);
    bool result_9 = rules.executeFirstRule(statusDead, neighbours_3);
    bool result_10 = rules.executeFirstRule(statusDead, neighbours_7);

    EXPECT_TRUE(result_1);
    EXPECT_TRUE(result_2);
    EXPECT_FALSE(result_3);
    EXPECT_FALSE(result_4);
    EXPECT_FALSE(result_5);
    EXPECT_FALSE(result_6);
    EXPECT_FALSE(result_7);
    EXPECT_FALSE(result_8);
    EXPECT_FALSE(result_9);
    EXPECT_FALSE(result_10);
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
    bool result_1 = rules.executeSecondRule(statusAlive, neighbours_0);
    bool result_2 = rules.executeSecondRule(statusAlive, neighbours_1);
    bool result_3 = rules.executeSecondRule(statusAlive, neighbours_2);
    bool result_4 = rules.executeSecondRule(statusAlive, neighbours_3);
    bool result_5 = rules.executeSecondRule(statusAlive, neighbours_7);
    bool result_6 = rules.executeSecondRule(statusDead, neighbours_0);
    bool result_7 = rules.executeSecondRule(statusDead, neighbours_1);
    bool result_8 = rules.executeSecondRule(statusDead, neighbours_2);
    bool result_9 = rules.executeSecondRule(statusDead, neighbours_3);
    bool result_10 = rules.executeSecondRule(statusDead, neighbours_7);

    EXPECT_FALSE(result_1);
    EXPECT_FALSE(result_2);
    EXPECT_FALSE(result_3);
    EXPECT_FALSE(result_4);
    EXPECT_TRUE(result_5);
    EXPECT_FALSE(result_6);
    EXPECT_FALSE(result_7);
    EXPECT_FALSE(result_8);
    EXPECT_FALSE(result_9);
    EXPECT_FALSE(result_10);
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
    bool result_1 = rules.executeThirdRule(statusAlive, neighbours_0);
    bool result_2 = rules.executeThirdRule(statusAlive, neighbours_1);
    bool result_3 = rules.executeThirdRule(statusAlive, neighbours_2);
    bool result_4 = rules.executeThirdRule(statusAlive, neighbours_3);
    bool result_5 = rules.executeThirdRule(statusAlive, neighbours_7);
    bool result_6 = rules.executeThirdRule(statusDead, neighbours_0);
    bool result_7 = rules.executeThirdRule(statusDead, neighbours_1);
    bool result_8 = rules.executeThirdRule(statusDead, neighbours_2);
    bool result_9 = rules.executeThirdRule(statusDead, neighbours_3);
    bool result_10 = rules.executeThirdRule(statusDead, neighbours_7);

    EXPECT_FALSE(result_1);
    EXPECT_FALSE(result_2);
    EXPECT_FALSE(result_3);
    EXPECT_FALSE(result_4);
    EXPECT_FALSE(result_5);
    EXPECT_FALSE(result_6);
    EXPECT_FALSE(result_7);
    EXPECT_FALSE(result_8);
    EXPECT_TRUE(result_9);
    EXPECT_FALSE(result_10);
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
    bool result_1 = rules.executeFourthRule(statusAlive, neighbours_0);
    bool result_2 = rules.executeFourthRule(statusAlive, neighbours_1);
    bool result_3 = rules.executeFourthRule(statusAlive, neighbours_2);
    bool result_4 = rules.executeFourthRule(statusAlive, neighbours_3);
    bool result_5 = rules.executeFourthRule(statusAlive, neighbours_7);
    bool result_6 = rules.executeFourthRule(statusDead, neighbours_0);
    bool result_7 = rules.executeFourthRule(statusDead, neighbours_1);
    bool result_8 = rules.executeFourthRule(statusDead, neighbours_2);
    bool result_9 = rules.executeFourthRule(statusDead, neighbours_3);
    bool result_10 = rules.executeFourthRule(statusDead, neighbours_7);

    EXPECT_FALSE(result_1);
    EXPECT_FALSE(result_2);
    EXPECT_TRUE(result_3);
    EXPECT_TRUE(result_4);
    EXPECT_FALSE(result_5);
    EXPECT_FALSE(result_6);
    EXPECT_FALSE(result_7);
    EXPECT_FALSE(result_8);
    EXPECT_FALSE(result_9);
    EXPECT_FALSE(result_10);
}
