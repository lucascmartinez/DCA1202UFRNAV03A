#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QString>
#include <QStringList>
#include <QList>
#include <QObject>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent), ui(new Ui::MainWindow){
  min = 0;
  max = 99;
  speed = 1;
  ipaddress = "127.0.0.1";
  ui->setupUi(this);
  socket = new QTcpSocket(this);
  opengate = false;
  timerctrl = startTimer(1000);
  connect(ui->pushSendData,
          SIGNAL(clicked(bool)),
          this,
          SLOT(putData()));
  connect(ui->pushStopData,
          SIGNAL(clicked(bool)),
          this,
          SLOT(stopData()));
  connect(ui->pushConnect,SIGNAL(clicked(bool)),this,SLOT(tcpConnect()));
  connect(ui->pushDisconnect,SIGNAL(clicked(bool)),this,SLOT(tcpDisconnect()));
  connect(ui->sliderMin,SIGNAL(sliderMoved(int)),this,SLOT(changeMin(int)));
  connect(ui->sliderMax,SIGNAL(sliderMoved(int)),this,SLOT(changeMax(int)));
  connect(ui->sliderSpeed,SIGNAL(sliderMoved(int)),this,SLOT(changeTiming(int)));
  connect(ui->inputIP,SIGNAL(textChanged(QString)),this,SLOT(setIP(QString)));
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    QDateTime datetime;
    QString str;
    qint64 msecdate;

    if ((opengate == true)) {
    if(socket->state()== QAbstractSocket::ConnectedState){

      msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
      str = "set "+ QString::number(msecdate) + " " + QString::number(qrand()% (max-min) + min)+"\r\n";
      showMessage(str);
      qDebug() << str;
            qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";
            if(socket->waitForBytesWritten(3000)){
              qDebug() << "wrote";
            }
    }
   }
}

void MainWindow::tcpConnect(){
  socket->connectToHost(ipaddress,1234);
}

void MainWindow::tcpDisconnect()
{
    socket->disconnectFromHost();
}

void MainWindow::showMessage(QString msg){
  ui->outputData->append(msg);
}

void MainWindow::changeMin(int _min)
{
    min = _min;
}

void MainWindow::changeMax(int _max)
{
    max = _max;
}

void MainWindow::changeTiming(int _speed)
{
  killTimer(timerctrl);
  timerctrl = startTimer(100*_speed);
}

void MainWindow::setIP(QString _ipaddress)
{
    ipaddress = _ipaddress;
}

void MainWindow::putData(){
    opengate = true;
}

void MainWindow::stopData()
{
    opengate = false;
}

MainWindow::~MainWindow(){
  delete socket;
    delete ui;
}
