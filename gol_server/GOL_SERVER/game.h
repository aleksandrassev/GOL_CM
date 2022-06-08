#ifndef GAME_H
#define GAME_H

#include <QTimer>
#include "gamelogic.h"
#include "encoder.h"
#include "rules.h"
#include "server.h"
#include "isignalhandler.h"
#include "mytimer.h"


class Game : public QObject, public ISignalHandler
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
    void onTimeout() override;

private:
    MyTimer *m_timer;
    GameLogic *m_glogic;
    IServer *m_server;
    Encoder* m_encoder;
    Rules* m_rules;
    Field* m_field;
    Field* m_nextField;
    int m_cycleInterval;
    int m_counter;
    bool m_isConnected;

    bool isFieldEmpty(QString &FieldString) const;
};

#endif // GAME_H
