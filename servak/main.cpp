#include "myservak.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GUI servak;

    servak.show();

    return a.exec();
}
