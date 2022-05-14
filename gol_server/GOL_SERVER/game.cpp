#include "game.h"


Game::Game(QObject *parent, IServer* server)
    : QObject{parent}
    , m_timer{nullptr}
    , m_cycle{nullptr}
    , m_server{server}
    , m_encoder{nullptr}
    , m_rules{nullptr}
    , m_field{nullptr}
    , m_cycleInterval{300}
    , m_counter{0}
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Game::run);
    m_timer->setInterval(m_cycleInterval);

    m_server->registerSignal(this);

    m_encoder = new Encoder();
    m_rules = new Rules();
    m_field = new Field();
    m_nextField = new Field();
    m_cycle = new Cycle(m_encoder, m_rules, m_field, m_nextField);
}

Game::~Game()
{
    delete m_cycle;
    m_cycle = nullptr;

    delete m_field;
    m_field = nullptr;

    delete m_nextField;
    m_nextField = nullptr;

    delete m_rules;
    m_rules = nullptr;

    delete m_encoder;
    m_encoder = nullptr;

    delete m_timer;
    m_timer = nullptr;
}

void Game::onNewConnection()
{
    qDebug() << "Draw input and press Start...";
}

void Game::onReadyRead()
{
    qDebug()<<"Game::onReadyRead starts";
    QString input = m_server->readData();

    *m_field = m_encoder->decode(input);

    if (input == "RestartServer")
    {
        restart();
        return;
    }

    m_timer->start();
}

void Game::run()
{
    qDebug()<<"Game::run starts";
    m_cycle->nextGeneration();
    delete m_cycle;

    m_cycle = new Cycle(m_encoder, m_rules, m_field, m_nextField);;
    QString encodedField = m_encoder->encode(m_field);

    m_counter++;
    qDebug() << "Game counter in server: " + QString::number(m_counter);

    m_server->writeData(encodedField + "!" + QString::number(m_counter));
}

void Game::restart()
{
    qDebug() << "game restart!";

    m_counter = 0;
    m_timer->stop();
    delete m_cycle;
}
