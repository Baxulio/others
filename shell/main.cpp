#include "shell.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    shell w;
    w.show();

    return a.exec();
}
