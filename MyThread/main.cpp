#include "mythread.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyThread w;

    QLCDNumber lcd;
    MyWo mywo;

    QObject::connect(&mywo, SIGNAL(valueChanged(int)),&lcd,SLOT(display(int)));

    lcd.setSegmentStyle(QLCDNumber::Filled);
    lcd.display(10);
    lcd.resize(220,90);
    lcd.show();

    mywo.moveToThread(&w);
    QObject::connect(&mywo,SIGNAL(finished()),&w,SLOT(quit()));
    QObject::connect(&w,SIGNAL(finished()),&a,SLOT(quit()));

    w.start();

    mywo.doWork();


    return a.exec();
}
