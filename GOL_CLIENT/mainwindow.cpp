#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
    , m_fieldScene(new FieldScene)
    , m_view(new QGraphicsView)
    , m_client(new MyClient)
{
    setFixedSize(840,560);

    m_ui->setupUi(this);

    m_fieldScene->createEmptyFieldImage();
    m_ui->graphicsView->setScene(m_fieldScene);

    m_ui->lineEditIP->setText("127.0.0.1");
    m_ui->lineEditPort->setText("12345");

    m_ui->labelCounter->setStyleSheet("font-weight: bold; color: blue; font-size: 18px");
    m_ui->labelConnection->setStyleSheet("font-weight: bold; color: red; font-size: 20px");
    m_ui->pushButtonStart->setEnabled(false);
    m_ui->pushButtonRestart->setEnabled(false);

    QObject::connect(m_client->getSocket(), &QTcpSocket::readyRead, this, &MainWindow::viewField);
    QObject::connect(m_client->getSocket(), &QTcpSocket::disconnected, this, &MainWindow::clientDisconnected);
}

MainWindow::~MainWindow()
{
    delete m_client;
    delete m_ui;
    delete m_fieldScene;
}

void MainWindow::on_pushButtonConnect_clicked()
{
    QString my_ip = m_ui->lineEditIP->text();
    int my_port = m_ui ->lineEditPort->text().toInt();

    if (m_ui->pushButtonConnect->text() == "Connect")
    {
        if (m_client->connectSocket(my_ip, my_port))
        {
            m_ui->pushButtonConnect->setText("Disconnect");
            m_ui->labelConnection->setStyleSheet("font-weight: bold; color: green; font-size: 20px");
            m_ui->labelConnection->setText("Connected!");
            m_ui->pushButtonStart->setEnabled(true);
            m_ui->pushButtonRestart->setEnabled(true);
        }
        else
        {
            m_ui->labelConnection->setText("Connection failed!");
            return;
        }
    }
    else
    {
        m_client->disconnectSocket();
        m_ui->pushButtonConnect->setText("Connect");
    }
}

void MainWindow::on_pushButtonStart_clicked()
{
    QString buffer;
    m_fieldScene->encodeImage(buffer);

    if (m_fieldScene->checkIfEmpty())
    {
        m_ui->labelCounter->setStyleSheet("font-weight: bold; color: red; font-size: 18px");
        m_ui->labelCounter->setText("Empty Field!");
        qDebug()<<"Warning: empty field in MainWindow";
        return;
    }
    m_client->writeData(buffer);
}

void MainWindow::viewField()
{
    QString buffer = m_client->readData();
    Encoder encoder;
    int actualCount = encoder.parseCounter(buffer);

    m_ui->labelCounter->setStyleSheet("font-weight: bold; color: blue; font-size: 18px");
    m_ui->labelCounter->setText(QString::number(actualCount));

    m_fieldScene->clearImage();
    m_fieldScene->decodeImage(buffer);

    if (m_fieldScene->checkIfEmpty())
    {
        m_ui->labelCounter->setStyleSheet("font-weight: bold; color: red; font-size: 18px");
        m_ui->labelCounter->setText("End!" + QString::number(actualCount));
        m_client->disconnectSocket();
    }
}

void MainWindow::clientDisconnected()
{
    m_ui->labelConnection->setStyleSheet("font-weight: bold; color: red; font-size: 20px");
    m_ui->labelConnection->setText("Disconnected!");
    m_ui->pushButtonConnect->setText("Connect");
    m_ui->pushButtonStart->setEnabled(false);
    m_ui->pushButtonRestart->setEnabled(false);
}

void MainWindow::on_pushButtonRestart_clicked()
{
    qDebug() << "initiate restart ...";

    m_client->writeData("2\n");

    m_fieldScene->clear();
    m_fieldScene->createEmptyFieldImage();
    m_fieldScene->makeEmpty();
}
