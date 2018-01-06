//#include "mainwindow.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w
    QGraphicsScene scene(QRectF(0,0,400,400));
    QGraphicsView view(&scene);


    QPushButton cmd("&Quit");
    QGraphicsProxyWidget* pproxyWgt = scene.addWidget(&cmd);
    QTransform trans = pproxyWgt->transform();

    trans.translate(100,350);
    trans.rotate(-45,Qt::YAxis);
    trans.scale(8,2);
    pproxyWgt->setTransform(trans);

    QObject::connect(&cmd, SIGNAL(clicked(bool)), &a, SLOT(quit()));

    QDial dial;
    dial.setNotchesVisible(1);
    pproxyWgt=scene.addWidget(&dial);
    trans=pproxyWgt->transform();

    trans.scale(4,2);
    trans.rotate(-45,Qt::YAxis);
    pproxyWgt->setTransform(trans);

    QProgressBar prb;
    prb.setFixedSize(500,40);
    pproxyWgt=scene.addWidget(&prb);
    trans=pproxyWgt->transform();

    trans.translate(20,200);
    trans.scale(2,2);
    trans.rotate(80,Qt::YAxis);
    trans.rotate(30,Qt::XAxis);
    pproxyWgt->setTransform(trans);

    QObject::connect(&dial, SIGNAL(valueChanged(int)), &prb, SLOT(setValue(int)));
    view.rotate(15);
    view.show();

    return a.exec();
}
