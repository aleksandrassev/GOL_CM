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

TEST_F(Game_test, onNewConnect)
{
    testing::NiceMock<MockServer> mockServer;
    ON_CALL(mockServer, registerSignal(_)).WillByDefault(testing::Return());

    class GameTester: public Game
    {
    public:
        GameTester (QObject *parent, IServer* server) : Game (parent, server) {}
        void onNewConnection() override
        {
            Game::onNewConnection();
        }
    };

    GameTester game(nullptr, &mockServer);
    game.onNewConnection();

    EXPECT_TRUE(game.getConStatus());
}
#include "mytimer.h"
TEST_F(Game_test, onTimeout)
{
    testing::NiceMock<MockServer> mockServer;
    ON_CALL(mockServer, registerSignal(_)).WillByDefault(testing::Return());

    //Game game(nullptr, &mockServer);
    MyTimer timer;
    timer.setInterval(300);
    timer.start();

}

TEST_F(Game_test, onDisconnected)
{
    testing::NiceMock<MockServer> mockServer;
    ON_CALL(mockServer, registerSignal(_)).WillByDefault(testing::Return());

    class GameTester: public Game
    {
    public:
        GameTester (QObject *parent, IServer* server) : Game (parent, server) {}
        void onNewConnection() override
        {
            Game::onNewConnection();
        }
        void onDisconnected() override
        {
            Game::onDisconnected();
        }
    };

    GameTester game(nullptr, &mockServer);
    game.onNewConnection();
    game.onDisconnected();

    EXPECT_FALSE(game.getConStatus());
}

TEST_F(Game_test, onNewConnection)
{
    testing::NiceMock<MockServer> mockServer;
    ON_CALL(mockServer, registerSignal(_)).WillByDefault(testing::Return());

    class GameTester: public Game
    {
    public:
        GameTester (QObject *parent, IServer* server) : Game (parent, server) {}
        void onNewConnection() override
        {
            Game::onNewConnection();
        }

    };
    GameTester game(nullptr, &mockServer);
    game.onNewConnection();

    EXPECT_TRUE(game.getConStatus());
}

TEST_F(Game_test, onReadyReadImpl_nullptr)
{
    testing::NiceMock<MockServer> mockServer;
    QString test = "265";

    Game game(nullptr, &mockServer);

    int status = game.onReadyReadImpl(test);

    EXPECT_EQ(status, 1);
}

TEST_F(Game_test, onReadyReadImpl_restart)
{
    testing::NiceMock<MockServer> mockServer;
    Game game(nullptr, &mockServer);

    QString test = "5\n";
    QString restart = "2\n";
    ON_CALL(mockServer, readData()).WillByDefault(testing::Return("5\n"));
    int tstatus = game.onReadyReadImpl(test);
    ON_CALL(mockServer, readData()).WillByDefault(testing::Return("2\n"));
    int rstatus = game.onReadyReadImpl(restart);

    EXPECT_EQ(rstatus, 2);
    EXPECT_EQ(tstatus, 1);
    EXPECT_NE(rstatus, 0);
    EXPECT_NE(tstatus, 0);
}


TEST_F(Game_test, run)
{
    testing::NiceMock<MockServer> mockServer;
    Game game(nullptr, &mockServer);

    QString encodedField1 = "00000000\n00100000\n00010000\n01110000\n00000000\n00000000\n00000000\n00000000\n";
    QString encodedField2 = "00000000\n00000000\n01010000\n00110000\n00100000\n00000000\n00000000\n00000000\n!1";

    ON_CALL(mockServer, readData()).WillByDefault(testing::Return("00000000\n"
                                                                  "00100000\n"
                                                                  "00010000\n"
                                                                  "01110000\n"
                                                                  "00000000\n"
                                                                  "00000000\n"
                                                                  "00000000\n"
                                                                  "00000000\n"));
    game.onReadyReadImpl(encodedField1);

    EXPECT_CALL(mockServer, writeData(encodedField2)).WillOnce(testing::Return());
    game.run();
}
