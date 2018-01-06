#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QWidget>
#include <QtWidgets>

class MyWo : public QObject
{
    Q_OBJECT
private:
    int value;
    QTimer timer;
public:
    MyWo(QObject *parent = 0):QObject(parent),value(0)
    {
        connect(&timer,SIGNAL(timeout()),SLOT(setNext()));
    }
    void doWork()
    {
        timer.start(1000);
    }

signals:
    void valueChanged(int);
    void finished();

public slots:
    void setNext()
    {
        emit valueChanged(--value);
        if(!value)
        {
            emit finished();
        }
    }

};

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread(){}
    void run()
    {
        exec();
    }
};

#endif // MYTHREAD_H
