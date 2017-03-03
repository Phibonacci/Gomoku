#ifndef TIME_HH
#define TIME_HH

#include <QLabel>
#include <QTimer>


class Time : public QLabel
{
    Q_OBJECT

    int         _min;
    int         _sec;
    int         _initmin;
    int         _initsec;
    QTimer*     _timer;
public:
    explicit Time(QWidget *parent = 0, int min = 0, int sec = 0);
    void     restart();
    ~Time();
    void     setMin(int min);

signals:
    void    Lose();

private slots:
    void    decSec();

public slots:
    void     stopTimer();
    void     startTimer();
};

#endif // TIME_HH
