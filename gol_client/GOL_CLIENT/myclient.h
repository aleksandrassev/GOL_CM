#ifndef MYCLIENT_H
#define MYCLIENT_H

#include <QObject>
#include <QTcpSocket>

#include "datahandler.h"

class MyClient : public QObject
{
    Q_OBJECT
public:
    explicit MyClient(QObject *parent = nullptr);

    bool connectSocket(QString my_ip, int my_port);
    void disconnectSocket();
    bool getSocketStatus();
    QTcpSocket* getSocket();

public slots:
    void writeData(QString stream);
    QByteArray readData();

private:
    QTcpSocket *m_socket;
    bool m_socketStatus;
};

#endif // MYCLIENT_H
