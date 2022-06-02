#ifndef GAME_H
#define GAME_H

#include <QTimer>
#include "cycle.h"
#include "encoder.h"
#include "rules.h"
#include "server.h"
#include "iserver_signal.h"


class Game : public QObject, public IServerSignal
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr, IServer* server = nullptr);
    ~Game();
    int onReadyReadImpl(QString &input);
    bool onNewConnectionImpl();
    void run();
    void restart();
    bool getConStatus();

protected:
    void onReadyRead() override;
    void onNewConnection() override;
    void onDisconnected() override;
private:
    QTimer *m_timer;
    Cycle *m_cycle;
    IServer *m_server;
    Encoder* m_encoder;
    Rules* m_rules;
    Field* m_field;
    Field* m_nextField;
    int m_cycleInterval;
    int m_counter;
    bool m_isConnected;
};

#endif // GAME_H
