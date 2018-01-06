#include "turtleworkarea.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TurtleWorkArea w;
    w.show();

    return a.exec();
}
