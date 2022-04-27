#include "server.h"

Server::Server(QObject *parent)
    : QObject{parent}
{
    m_server = new QTcpServer();
    connect(m_server, &QTcpServer::newConnection, this, &Server::newConnect);
    start();
}

Server::~Server()
{
    m_server -> close();
    delete m_server;
}

void Server::start()
{
    if(!m_server->listen(QHostAddress::LocalHost, 12345))
    {
        qDebug()<<m_server->errorString();
        return;
    }
    qDebug()<<"Server started! Waiting for client...";
}

void Server::newConnect()
{
    m_socket = m_server->nextPendingConnection();

    connect(m_socket, &QTcpSocket::disconnected, this, &Server::disconnected);

    qDebug()<<"Connected!";
}

QByteArray Server::readData()
{
    QByteArray buffer = m_socket->readAll();

    return buffer;
}

void Server::writeData(QString buffer)
{
    m_socket->write(buffer.toLatin1());
    m_socket->flush();
}

void Server::disconnected()
{
    qDebug()<<"Disconnected...";
}

QTcpSocket* Server::getSocket()
{
    return m_socket;
}

QTcpServer* Server::getServer()
{
    return m_server;
}

