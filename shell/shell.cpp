#include "shell.h"

shell::shell(QWidget *parent)
    : QWidget(parent)
{
    proc = new QProcess(this);
    txted = new QTextEdit;
    QLabel *plb=new QLabel("&suka komanda: ");

    led=new QLineEdit("dir");

    plb->setBuddy(led);
    QPushButton *pcmd=new QPushButton("&Enter");

    connect(proc,SIGNAL(readyReadStandardOutput()), SLOT(slotDataOnStdout()));
    connect(led, SIGNAL(returnPressed()),SLOT(slotReturnPressed()));
    connect(pcmd, SIGNAL(clicked(bool)),SLOT(slotReturnPressed()));

    QHBoxLayout *h=new QHBoxLayout;
    h->addWidget(plb);
    h->addWidget(led);
    h->addWidget(pcmd);

    QVBoxLayout *v=new QVBoxLayout;
    v->addWidget(txted);
    v->addLayout(h);

    setLayout(v);
}
void shell::slotDataOnStdout()
{
    txted->append(proc->readAllStandardOutput());
}
void shell::slotReturnPressed()
{
    QString str="";
#ifdef Q_WS_WIN
    str="cmd /C ";
#endif
    str+=led->text();
    proc->start(str);
}

shell::~shell()
{

}
