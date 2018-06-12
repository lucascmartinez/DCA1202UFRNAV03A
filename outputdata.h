#ifndef OUTPUTDATA_H
#define OUTPUTDATA_H

#include <QWidget>

class OutputData : public QWidget
{
    Q_OBJECT
private:
    int min, max, speed;
public:
    explicit OutputData(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // OUTPUTDATA_H
