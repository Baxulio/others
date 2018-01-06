#ifndef TURTLEWORKAREA_H
#define TURTLEWORKAREA_H

#include <QWidget>
#include <turtle.h>
#include <QScriptEngine>

class QTextEdit;
class turtle;

class TurtleWorkArea : public QWidget
{
    Q_OBJECT
private:
    QTextEdit *m_ptxt;
    QScriptEngine m_scriptEngine;
    turtle* m_pTurtle;
public:
    TurtleWorkArea(QWidget *parent = 0);
    ~TurtleWorkArea();
private slots:
    void slotEvaluate();
    void slotApplyCode(int);
};

#endif // TURTLEWORKAREA_H
