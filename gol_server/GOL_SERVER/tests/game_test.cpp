#include "game_test.h"
#include "mockserver.h"

using testing::_;

TEST_F(Game_test, start)
{
    testing::NiceMock<MockServer> mockServer;
    ON_CALL(mockServer, registerSignal(_)).WillByDefault(testing::Return());

    Game game(nullptr, &mockServer);

    SUCCEED();
}

TEST_F(Game_test, onReadyRead)
{
    testing::NiceMock<MockServer> mockServer;
    ON_CALL(mockServer, readData()).WillByDefault(testing::Return("MockSignal"));

    Game game(nullptr, &mockServer);
    game.onReadyRead();
}

//TEST_F(Game_test, run)
//{
//    testing::NiceMock<MockServer> mockServer;
//    QString buffer;
//    EXPECT_CALL(mockServer, writeData(buffer)).WillOnce(testing::Return());

//    Game game(nullptr, &mockServer);
//    game.run();
//}
