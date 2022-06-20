#include "gtest/gtest.h"
#include "server.h"
#include <QDebug>

class Server_test: public:: testing:: Test
{
};

TEST_F(Server_test, constructor)
{
    Server server;

    EXPECT_TRUE(server.getServer());
}

TEST_F(Server_test, constructor_server_start)
{
    Server server;

    server.startListening();

    EXPECT_TRUE( server.getServer()->isListening());
}

