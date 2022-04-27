#include "game.h"


Game::Game(QObject *parent)
    : QObject{parent}
{
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &Game::run);
    m_timer->setInterval(m_cycleInterval);

    m_server = new Server(this);
    connect(m_server->getServer(), &QTcpServer::newConnection, this, &Game::start);

    m_encoder = new Encoder();
    m_rules = new Rules();
    m_field = nullptr;
}

Game::~Game()
{
    delete m_rules;
    delete m_encoder;
    delete m_field;
    delete m_timer;
    delete m_server;
}

void Game::start()
{
    qDebug() << "Draw input and press Start...";

    //connect(m_server->getSocket(), &QTcpSocket::readyRead, this, &Game::initialize);
}

void Game::initialize()
{
    QString input = m_server->readData();

    if (input == "RestartServer")
    {
        restart();
        return;
    }
    m_cycle = new Cycle(m_encoder, m_rules);
    m_field = new Field(m_encoder->decode(input));
    m_timer->start();
}

void Game::run()
{
    m_cycle->nextGeneration(m_field);
    delete m_cycle;

    m_cycle = new Cycle(m_encoder, m_rules);;
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
