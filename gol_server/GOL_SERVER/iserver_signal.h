#ifndef ISERVERSIGNAL_H
#define ISERVERSIGNAL_H

class IServerSignal
{
public:
    virtual void onNewConnection() = 0;
    virtual void onReadyRead() = 0;
    virtual void onDisconnected() = 0;


protected:
    virtual ~IServerSignal() = default;
};

#endif // ISERVERSIGNAL_H
