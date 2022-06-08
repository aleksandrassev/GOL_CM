#include "myclient.h"

MyClient::MyClient(QObject *parent)
    : QObject{parent}
{
    m_socket = new QTcpSocket();
    m_socket->setSocketOption(QAbstractSocket::KeepAliveOption, 1);
}

bool MyClient::connectSocket(QString my_ip, int my_port)
{
    m_socket->abort();
    m_socket->connectToHost(my_ip, my_port);

    if(!m_socket->waitForConnected(2000))
    {
        return false;
    }
    m_socketStatus = true;

    return true;
}

void MyClient::disconnectSocket()
{
    m_socket->abort();
    m_socketStatus = false;
}

void MyClient::writeData(QString buffer)
{
    m_socket->write(buffer.toLatin1());
    m_socket->flush();
}

QByteArray MyClient::readData()
{
    QByteArray buffer;
    buffer = m_socket->readAll();

    return buffer;
}

QTcpSocket* MyClient::getSocket()
{
    return m_socket;
}
