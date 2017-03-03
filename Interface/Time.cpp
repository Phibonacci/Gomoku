#include "Time.hh"
#include <QVariant>
#include <QDebug>

Time::Time(QWidget *parent, int min, int sec)
    : QLabel(parent)
    , _min(min)
    , _sec(sec)
    , _initmin(min)
    , _initsec(sec)
    , _timer(new QTimer(this))
{
    setText(QVariant(_min).toString() + " : " + QVariant(_sec).toString());
    if (_min > 0)
        connect(_timer, SIGNAL(timeout()), this, SLOT(decSec()));
    else
        setHidden(true);
}

void        Time::restart() {
    _sec = _initsec;
    _min = _initmin;
}

void        Time::setMin(int min) {
    _min = min;
    _initmin = min;
    _sec = 0;
    setText(QVariant(_min).toString() + " : " + QVariant(_sec).toString());
}

void        Time::decSec()
{
    --_sec;
    if (_sec < 0)
    {
        _sec = 59;
        --_min;
        if (_min < 0)
        {
            emit Lose();
            qDebug() << "lose !";
        }
    }
    setText(QVariant(_min).toString() + " : " + QVariant(_sec).toString());
}

void        Time::startTimer()
{
    _timer->start(1000);
}

void        Time::stopTimer()
{
    _timer->stop();
}

Time::~Time()
{
}
