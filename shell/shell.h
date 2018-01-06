#ifndef SHELL_H
#define SHELL_H

#include <QtWidgets>
#include <QWidget>


class shell : public QWidget
{
    Q_OBJECT
private:
    QProcess *proc;
    QTextEdit *txted;
    QLineEdit *led;

public:
    shell(QWidget *parent = 0);

    ~shell();
public slots:
    void slotDataOnStdout();
    void slotReturnPressed();
};

#endif // SHELL_H
