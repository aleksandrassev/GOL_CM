#ifndef ISERVERSIGNAL_H
#define ISERVERSIGNAL_H

class ISignalHandler
{
public:
    virtual void onNewConnection() = 0;
    virtual void onReadyRead() = 0;
    virtual void onDisconnected() = 0;
    virtual void onTimeout() = 0;

protected:
    virtual ~ISignalHandler() = default;
};

#endif // ISERVERSIGNAL_H
