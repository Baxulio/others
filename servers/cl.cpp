#include "cl.h"

cl::cl(const QString strHost, int nPort, QWidget *parent) : QWidget(parent), nNextBlockSize(0)
{
    ptcpSocket=new QTcpSocket(this);

    ptcpSocket->connectToHost(strHost, nPort);
    connect(ptcpSocket, SIGNAL(connected()),SLOT(slotConnected()));

    connect(ptcpSocket, SIGNAL(readyRead()),SLOT(slotReadyRead()));

    connect(ptcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(slotError(QAbstractSocket::SocketError)));

    ptxt=new QTextEdit;
    ptxtInput=new QLineEdit;

    ptxt->setReadOnly(true);
    QPushButton *ppb=new QPushButton("&Send");
    connect(ppb, SIGNAL(clicked(bool)), SLOT(slotSendToServer()));
    connect(ptxtInput, SIGNAL(returnPressed()), this, SLOT(slotSendToServer()));


    QVBoxLayout *v=new QVBoxLayout;
    v->addWidget(new QLabel("<H1>Client</H1>"));
    v->addWidget(ptxt);
    v->addWidget(ptxtInput);
    v->addWidget(ppb);
    setLayout(v);

    //ptxtInput->setText("Sex");
    //slotSendToServer();
}
void cl::slotReadyRead()
{
    QDataStream in(ptcpSocket);
    in.setVersion(QDataStream::Qt_5_5);
    for(;;)
    {
        if(!nNextBlockSize)
        {
            if(ptcpSocket->bytesAvailable()<sizeof(quint16))
                break;

        in>>nNextBlockSize;
        }

    if(ptcpSocket->bytesAvailable()<nNextBlockSize)
        break;
    QTime time;
    QString str;
    in>>time>>str;

    ptxt->append(time.toString()+" "+str);
    nNextBlockSize=0;
    }
}
void cl::slotError(QAbstractSocket::SocketError err)
{
    QString strError=     "Error: "+(err==QAbstractSocket::HostNotFoundError?
                                     "The host not found.":
                                     err==QAbstractSocket::RemoteHostClosedError?
                                     "The remote host is closed.":
                                     err==QAbstractSocket::ConnectionRefusedError?
                                     "The connection was refused.":
                                     QString(ptcpSocket->errorString()));
    ptxt->append(strError);
}
void cl::slotSendToServer()
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_5);
    out<<quint16(0)<<QTime::currentTime()<<ptxtInput->text();

    out.device()->seek(0);
    out<<quint16(arrBlock.size()-sizeof(quint16));

    ptcpSocket->write(arrBlock);
    ptxtInput->clear();
}
void cl::slotConnected()
{
    ptxt->append("Recieved the connected() signal");
}

