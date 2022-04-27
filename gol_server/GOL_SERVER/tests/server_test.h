#ifndef SERVER_TEST_H
#define SERVER_TEST_H

#include "gtest/gtest.h"
#include "server.h"
#include <QDebug>

class Server_test: public:: testing:: Test
{
protected:
    Server_test() = default;
    virtual ~Server_test() = default;
};


#endif // SERVER_TEST_H
