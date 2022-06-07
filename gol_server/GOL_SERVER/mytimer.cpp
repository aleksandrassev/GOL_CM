#include "mytimer.h"

MyTimer::MyTimer(QTimer *parent)
    : QTimer{parent}
{
    connect(this, &MyTimer::timeout, this, &MyTimer::onTimeout);
}

MyTimer::~MyTimer()
{
}

void MyTimer::registerTimerSignal(ISignalHandler* callback)
{
    m_callback = callback;
}

void MyTimer::onTimeout()
{
    if (m_callback != nullptr)
    {
        m_callback->onTimeout();
    }
}
