#ifndef CL_H
#define CL_H

#include <QWidget>
#include <QTcpSocket>
#include <QtWidgets>

class cl : public QWidget
{
    Q_OBJECT
public:
    explicit cl(const QString strHost="localhost", int nPort=2323, QWidget *parent = 0);

private:
    QTextEdit* ptxt;
    QLineEdit *ptxtInput;
    QTcpSocket *ptcpSocket;
    quint16 nNextBlockSize;
public slots:
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError);
    void slotSendToServer();
    void slotConnected();
};

#endif // CL_H
