#ifndef MYSERVAK_H
#define MYSERVAK_H

#include <QWidget>
#include <QUrl>
#include <downloader.h>
#include <QtWidgets>

class GUI: public QWidget
{
    Q_OBJECT
private:
    MyServak *pms;
    QProgressBar *pprb;
    QLineEdit *ple;
    QPushButton *ppb;

    void showPic(const QString&);
public:
    GUI(QWidget *parent=0);
private slots:
    void slotGo();
    void slotError();
    void slotDownloadProgress(qint64,qint64 );
    void slotDone(const QUrl&, const QByteArray&);

};

#endif // MYSERVAK_H
