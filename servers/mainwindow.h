#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtWidgets>

class MainWindow;
class QTcpServer;
class QTcpSocket;
class QTextEdit;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(int nPort, QWidget *parent = 0);
    ~MainWindow();

private:
    QTextEdit* ptxt;
    QTcpServer *ptcpServer;
    quint16 nNextBlockSize;
private:
    void sendToClient(QTcpSocket* pSocket, const QString& str);
public slots:
    virtual void slotNewConnection();
    void slotReadClient();
};

#endif // MAINWINDOW_H
