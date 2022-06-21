#include "mainwindow.h"
#include "gtest/gtest.h"
#include <QApplication>
#include <QCoreApplication>

#define RUN_TEST 0

#if RUN_TEST == 1
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
#else
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
#endif
