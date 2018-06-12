#include "outputdata.h"
#include <QMouseEvent>
#include <cmath>
#include <QDebug>


OutputData::OutputData(QWidget *parent) : QWidget(parent)
{
    min = 0;
    max = 99;
    speed = 1;
    ipaddress = "127.0.0.1"
    startTimer(1000);
    setMouseTracking(true);
}
