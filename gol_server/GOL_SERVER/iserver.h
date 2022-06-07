#ifndef ISERVER_H
#define ISERVER_H

#include <QString>
#include <isignalhandler.h>

class IServer
{
public:
    virtual void writeData(QString buffer) = 0;
    virtual QByteArray readData() = 0;
    virtual void registerSignal(ISignalHandler* callback) = 0;
    virtual void startListening() = 0;

    virtual ~IServer() = default;
};

#endif // ISERVER_H
