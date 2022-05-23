#include "server.h"

Server::Server(QObject *parent)
    : QObject{parent}
    , m_callback{nullptr}
{
    m_server = new QTcpServer();
    connect(m_server, &QTcpServer::newConnection, this, &Server::onNewConnection);
}

Server::~Server()
{
    m_callback = nullptr;
    m_server -> close();
    delete m_server;
    m_server = nullptr;
}

void Server::startListening()
{
    if(!m_server->listen(QHostAddress::LocalHost, 12345))
    {
        qDebug()<<m_server->errorString();
        return;
    }
    qDebug()<<"Server started! Waiting for client...";
}

void Server::onNewConnection()
{
    if (m_callback != nullptr)
    {
        m_callback->onNewConnection();
    }

    m_socket = m_server->nextPendingConnection();

    connect(m_socket, &QTcpSocket::readyRead, this, &Server::onReadyRead);
    connect(m_socket, &QTcpSocket::disconnected, this, &Server::onDisconnected);

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

void Server::onDisconnected()
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

void Server::registerSignal(IServerSignal* callback)
{
    m_callback = callback;
}

void Server::onReadyRead()
{
    if (m_callback != nullptr)
    {
        m_callback->onReadyRead();
    }
}
