#include "Time.hh"
#include "ui_time.h"

Time::Time(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Time)
{
    ui->setupUi(this);
}

Time::~Time()
{
    delete ui;
}
