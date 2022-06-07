#ifndef MYTIMER_H
#define MYTIMER_H

#include <QTimer>
#include <QObject>
#include <QDebug>
#include <isignalhandler.h>

class MyTimer : public QTimer
{
    Q_OBJECT
public:
    explicit MyTimer(QTimer *parent = nullptr);
    ~MyTimer() override;

    void registerTimerSignal(ISignalHandler* callback);

private slots:
    void onTimeout();

private:
    ISignalHandler* m_callback;
};

#endif // MYTIMER_H
