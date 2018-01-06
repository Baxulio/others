#ifndef CLIENT_H
#define CLIENT_H

#include <QTcpSocket>
#include <QtWidgets>

class QTcpSocket;
class QTextEdit;
class QLineEdit;

class Client : public QWidget
{
    Q_OBJECT

public:
    explicit Client(const QString &strHost, int nPort, QWidget *pwg=0);
    ~Client();
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
#endif // CLIENT_H

