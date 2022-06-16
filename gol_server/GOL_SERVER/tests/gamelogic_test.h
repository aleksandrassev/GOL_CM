#ifndef GameLogic_TEST_H
#define GameLogic_TEST_H

#include "gtest/gtest.h"
#include "gamelogic.h"
#include "encoder.h"
#include "rules.h"
#include "QDebug"

class GameLogic_test : public :: testing :: Test
{
protected:
    GameLogic_test() = default;
    virtual ~GameLogic_test() = default;

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
    Field* field;
    Field* nextField;
    Encoder* encoder;
    Rules* rules;
    GameLogic* glogic;
};

#endif // GameLogic_TEST_H
