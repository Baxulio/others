#include "drag.h"
#include "drop.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    drag w;
    drop d;
    w.show();

    d.resize(400,400);
    d.show();
    return a.exec();
}
