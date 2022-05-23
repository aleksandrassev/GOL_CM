#ifndef MYSERVER_H
#define MYSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <iserver.h>
#include <iserver_signal.h>

class Server : public QObject, public IServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    ~Server();

    QTcpSocket* getSocket();
    QTcpServer* getServer();
    QByteArray readData() override;
    void registerSignal(IServerSignal* callback) override;
    void writeData(QString buffer) override;
    void startListening() override;

private slots:
    void onReadyRead();
    void onNewConnection();
    void onDisconnected();

private:
    QTcpServer* m_server;
    QTcpSocket* m_socket;
    IServerSignal* m_callback;


};

#endif // MYSERVER_H
