#include "game.h"


Game::Game(QObject *parent, IServer* server)
    : QObject{parent}
    , m_timer{nullptr}
    , m_glogic{nullptr}
    , m_server{server}
    , m_encoder{nullptr}
    , m_rules{nullptr}
    , m_field{nullptr}
    , m_cycleInterval{300}
    , m_counter{0}
{
    if (m_server == nullptr)
    {
      qCritical("missing pointer in Game::Game()");
      return;
    }

    m_timer = new MyTimer(this);
    m_timer->registerTimerSignal(this);
    m_timer->setInterval(m_cycleInterval);

    m_server->registerSignal(this);
    m_server->startListening();

    m_encoder = new Encoder();
    m_rules = new Rules();
    m_field = new Field();
    m_nextField = new Field();

    m_isConnected = false;
}

Game::~Game()
{
    delete m_glogic;
    m_glogic = nullptr;

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
    m_isConnected = true;
}

void Game::onDisconnected()
{
    m_isConnected = false;
}

void Game::onReadyRead()
{
   QString input;
   onReadyReadImpl(input);
}

int Game::onReadyReadImpl(QString &input)
{
    m_glogic = new GameLogic(m_encoder, m_rules, m_field, m_nextField);

    if (m_server == nullptr || m_field == nullptr || m_nextField == nullptr || m_encoder == nullptr || m_rules == nullptr)
    {
      qCritical("missing pointer in Game::onReadyRead()");
      return 0;
    }
    input = m_server->readData();

    if (input == "2\n")
    {
        restart();
        return 2;
    }
    *m_field = m_encoder->decode(input);
    *m_nextField = m_encoder->decode(input);

    m_timer->start();
    return 1;
}

void Game::onTimeout()
{
    run();
}

void Game::run()
{
   QString encodedField = m_glogic->nextGeneration();

   delete m_glogic;
    m_glogic = nullptr;

    *m_field = *m_nextField;
    m_glogic = new GameLogic(m_encoder, m_rules, m_field, m_nextField);;

    m_counter++;
    qDebug() << "Game counter in server: " + QString::number(m_counter);

    m_server->writeData(encodedField + "!" + QString::number(m_counter));

    if (isFieldEmpty(encodedField))
    {
        qDebug()<<"Field became empty!";
        restart();
        return;
    }
}

void Game::restart()
{
    qDebug() << "game restart!";

    m_counter = 0;
    m_timer->stop();
    delete m_glogic;
    m_glogic = nullptr;
}

bool Game::getConStatus()
{
    return m_isConnected;
}

bool Game::isFieldEmpty(QString &FieldString) const
{
    if (FieldString.contains("1"))
    {
        return false;
    }
    return true;
}
