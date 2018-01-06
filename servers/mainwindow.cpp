#include "mainwindow.h"

MainWindow::MainWindow(int nPort, QWidget *parent) :
    QWidget(parent),
    nNextBlockSize(0)
{
    ptcpServer=new QTcpServer(this);
    if(!ptcpServer->listen(QHostAddress::Any, nPort))
    {
        QMessageBox::critical(0, "Server Error", "Unable to start the server:"+ptcpServer->errorString());
        ptcpServer->close();
        return;
    }
    connect(ptcpServer, SIGNAL(newConnection()),this, SLOT(slotNewConnection()));

    ptxt=new QTextEdit;
    ptxt->setReadOnly(true);

    QVBoxLayout* v=new QVBoxLayout;
    v->addWidget(new QLabel("<H1>Server</H1>"));
    v->addWidget(ptxt);
    setLayout(v);

}

MainWindow::~MainWindow()
{
}
void MainWindow::slotNewConnection()
{
    QTcpSocket* pClientSocket=ptcpServer->nextPendingConnection();
    connect(pClientSocket, SIGNAL(disconnected()), pClientSocket, SLOT(deleteLater()));
    connect(pClientSocket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));
    sendToClient(pClientSocket, "Server Response: Connected!");
}
void MainWindow::slotReadClient()
{
    QTcpSocket *pClientSocket=(QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_5_5);
    for(;;)
    {
        if(!nNextBlockSize)
        {
            if(pClientSocket->bytesAvailable()<sizeof(quint16))
                break;

        in>>nNextBlockSize;
        }

    if(pClientSocket->bytesAvailable()<nNextBlockSize)
        break;
    QTime time;
    QString str;
    in>>time>>str;

    QString strMessage=time.toString()+" "+"Client has sent - "+str;
    ptxt->append(strMessage);

    nNextBlockSize=0;
    sendToClient(pClientSocket, "Server Response: Recieved \""+str+"\"");
    }
}
void MainWindow::sendToClient(QTcpSocket *pSocket, const QString &str)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    out<<quint16(0)<<QTime::currentTime()<<str;

    out.device()->seek(0);
    out<<quint16(arrBlock.size()-sizeof(quint16));

    pSocket->write(arrBlock);
}
