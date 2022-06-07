#ifndef MOCKSERVER_H
#define MOCKSERVER_H

#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "game.h"
#include <QDebug>


class MockServer: public IServer
{
public:
    MOCK_METHOD(void, writeData, (QString buffer), (override));
    MOCK_METHOD(QByteArray, readData, (), (override));
    MOCK_METHOD(void, registerSignal, (ISignalHandler* callback), (override));
    MOCK_METHOD(void, startListening, (), (override));

};

#endif // MOCKSERVER_H
