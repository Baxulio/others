
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel lb1("Window1");
    QLabel lb2("Window2");

    QPropertyAnimation* panim1 = new QPropertyAnimation(&lb1, "geometry");
    panim1->setDuration(3000);
    panim1->setStartValue(QRect(120, 0, 100, 100));
    panim1->setEndValue(QRect(480, 380, 200, 200));
    panim1->setEasingCurve(QEasingCurve::InOutExpo);

    QPropertyAnimation* panim2=new QPropertyAnimation(&lb2, "pos");

    panim2->setDuration(3000);
    panim2->setStartValue(QPoint(240,0));
    panim2->setEndValue(QPoint(240,480));
    panim2->setEasingCurve(QEasingCurve::OutBounce);

    QParallelAnimationGroup group;
    group.addAnimation(panim1);
    group.addAnimation(panim2);
    group.setLoopCount(3);
    group.start();

    lb1.show();
    lb2.show();

    return a.exec();
}
