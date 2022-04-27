#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>


class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();

    QTcpSocket* getSocket();
    QTcpServer* getServer();
    QByteArray readData();
    void writeData(QString buffer);

private slots:
    void start();
    void newConnect();
    void disconnected();

private:
    QTcpServer* m_server;
    QTcpSocket* m_socket;


};

#endif // MYSERVER_H
