#include "mainwindow.h"
#include <QApplication>
#include <QMouseEvent>
#include <QPushButton>
void yes()
{
    QMessageBox::aboutQt(0);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QTranslator translate;
    translate.load("ru.qm",".");
    qApp->installTranslator(&translate);


    QWidget wgt;
    QPushButton *pcmdA=new QPushButton(QObject::tr("Download"));
    QPushButton *pcmdB=new QPushButton(QObject::tr("Save"));
    QPushButton *pcmdC=new QPushButton(QObject::tr("Exit"));



    QVBoxLayout *pvbl=new QVBoxLayout;
    pvbl->addWidget(pcmdA);
    pvbl->addWidget(pcmdB);
    pvbl->addWidget(pcmdC);

    wgt.setLayout(pvbl);

    QFile file("://simple.qss");
    file.open(QFile::ReadOnly);
    QString strCSS=QLatin1String(file.readAll());

    qApp->setStyleSheet(strCSS);



    wgt.show();
    yes();
    return a.exec();
}
