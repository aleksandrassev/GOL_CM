#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>

#include <fstream>
#include <iostream>

#include "fieldscene.h"
#include "datahandler.h"
#include "myclient.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonStart_clicked();
    void on_pushButtonConnect_clicked();
    void viewField();
    void clientDisconnected();
    void on_pushButtonRestart_clicked();

private:
    Ui::MainWindow *m_ui;
    FieldScene *m_fieldScene;
    QGraphicsView *m_view;
    MyClient *m_client;
    DataHandler *m_dataHandler;

};
#endif // MAINWINDOW_H
