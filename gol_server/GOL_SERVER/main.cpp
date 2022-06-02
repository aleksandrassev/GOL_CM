#include <QCoreApplication>
#include "gtest/gtest.h"

#include "game.h"
#include "server.h"

#define RUN_TEST 1

#if RUN_TEST == 1
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
#else
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;

    Game game(nullptr, &server);

    return a.exec();
}
#endif
