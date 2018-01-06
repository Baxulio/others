#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets>
#include <QtScript>
#include <QScriptEngineDebugger>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QScriptEngine scriptEngine;
    QScriptEngineDebugger scrDeb;

    scrDeb.attachTo(&scriptEngine);

    QAction *pact=scrDeb.action(QScriptEngineDebugger::InterruptAction);
    pact->trigger();
    QString strCode = "var sum = 0; \n"
                      "for(var i=1; i<5; i++){\n"
                      "sum+=i; \n"
                        "}";
    QScriptValue result=scriptEngine.evaluate(strCode);

    return a.exec();
}
