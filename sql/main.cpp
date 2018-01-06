#include <QCoreApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setHostName("localhost");
    db.setPassword("");

    if(!db.open())
    {
       qDebug()<<"Can't open DB: "<<db.lastError();
       return false;
    }
    return true;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(!createConnection())
    {
        return -1;
    }

//    QSqlQuery query;

//    QString str = "CREATE TABLE boo("
//                  "number INTEGER PRIMARY KEY NOT NULL, "
//                  "name VARCHAR(15), "
//                  "phone VARCHAR(12), "
//                  "email VARCHAR(15) "
//                  ");";
//    if(!query.exec(str))
//    {
//        qDebug()<<"Unable to create a table";
//    }

//    query.prepare("INSERT INTO boo (number, name, phone, email) ""VALUES(:number, :name, :phone, :email);");
//    query.bindValue(":number",1);
//    query.bindValue(":name","wer");
//    query.bindValue(":phone","er");
//    query.bindValue(":email","bakhmanyor@mail.ru");

//    if(!query.exec())
//    {
//        qDebug()<<"Unable to fill the table";
//    }

//    if(!query.exec("SELECT *FROM boo;"))
//    {
//        qDebug()<<"Unable to exec query - exiting...";
//        return 1;
//    }
//    while(query.next())
//    {
//        qDebug()<<"ID: "<<query.value(query.record().indexOf("number")).toInt()<<" "
//                <<"Name: "<<query.value(query.record().indexOf("name")).toString()<<";\t"
//                <<"Phone: "<<query.value(query.record().indexOf("phone")).toString()<<";\t"
//                <<"E-Mail: "<<query.value(query.record().indexOf("email")).toString();
//    }

    return a.exec();
}

