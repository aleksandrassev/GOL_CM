#ifndef GAME_TEST_H
#define GAME_TEST_H

#include "gtest/gtest.h"
#include "game.h"
#include <QDebug>

class Game_test: public:: testing:: Test
{
protected:
    Game_test() = default;
    virtual ~Game_test() = default;
};

#endif // GAME_TEST_H
