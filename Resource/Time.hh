#ifndef TIME_HH
#define TIME_HH

#include <QWidget>

namespace Ui {
class Time;
}

class Time : public QWidget
{
    Q_OBJECT

public:
    explicit Time(QWidget *parent = 0);
    ~Time();

private:
    Ui::Time *ui;
};

#endif // TIME_HH
