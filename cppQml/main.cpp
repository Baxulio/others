#include <QApplication>
#include <QQmlApplicationEngine>
#include <wgtqml.h>
#include <QtQml>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImageProvider("brightness", new wgtqml);
    engine.load(QUrl("qrc:/main.qml"));

   return app.exec();
}
