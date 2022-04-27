#ifndef GAME_H
#define GAME_H

#include <QTimer>
#include "cycle.h"
#include "encoder.h"
#include "rules.h"
#include "server.h"


class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
    ~Game();

public slots:
    void start();
    void run();
    void initialize();
    void restart();

private:
    QTimer *m_timer;
    Cycle *m_cycle;
    Server *m_server;
    Encoder* m_encoder;
    Rules* m_rules;
    Field* m_field;

    int m_cycleInterval = 300;
    int m_counter = 0;
};

#endif // GAME_H
