#include <QApplication>

#include "mainwindow.h"
#include "cl.h"
#include "QtSql"

static bool createConnection()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("book");
    db.setHostName("Bahman");
    db.setUserName("Djalol");
    db.setPassword("1");

    if(!db.open())
    {
        qDebug()<<"Cannot open db: "<<db.lastError();
        return false;
    }

//    QStringList lst = db.tables();
//    foreach (QString str, lst) {

//        qDebug()<<"Table:"<<str;
//    }
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w(2323);
    w.show();

    cl *client=new cl;
    client->show();
    //for(int i=0; i<100; i++)client[i].show();

    if(createConnection())
    {
    }

    return a.exec();
}
