#include <QCoreApplication>
#include "gtest/gtest.h"

#include "game.h"
#include "server.h"

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    Server server;

//    Game game(nullptr, &server);

//    return a.exec();
//}

