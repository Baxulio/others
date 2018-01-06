//#include "widget.h"
#include <QApplication>
#include <QTcpServer>
#include <QDateTime>
#include <QTcpSocket>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();
    QTcpServer tcpServer;
    int nPort = 2424;

    if(!tcpServer.listen(QHostAddress::Any, nPort))
    {
        qDebug()<<"Can't listen on port: "<<nPort;
        return 0;
    }

    forever
    {
        while(tcpServer.waitForNewConnection(30000))
        {
            do
            {
                QTcpSocket *pSocket =tcpServer.nextPendingConnection();
                QString strdt = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
                pSocket->write(strdt.toLatin1());
                pSocket->flush();
                qDebug()<<"Server date & time: "+strdt;
                pSocket->disconnectFromHost();
                if(pSocket->state() == QAbstractSocket::ConnectedState)
                {
                    pSocket->waitForDisconnected();
                }
                delete pSocket;
            }
            while(tcpServer.hasPendingConnections());
        }
    }


    return a.exec();
}
