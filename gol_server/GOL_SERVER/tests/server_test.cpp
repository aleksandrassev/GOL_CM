#include "server_test.h"


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

