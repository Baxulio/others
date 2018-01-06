#include <QApplication>
#include "oglpyramid.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OGLPyramid pyra;

    pyra.resize(200,200);
    pyra.show();

    return a.exec();
}
