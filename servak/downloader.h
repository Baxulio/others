#ifndef DOWNLOADER
#define DOWNLOADER

#include<QObject>
#include <QUrl>
#include <QtNetwork>

class QNetworkAccessManager;
class QNetworkReply;

class MyServak : public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager *pacm;

public:
    MyServak(QObject *parent = 0);
    void download(const QUrl&);

    ~MyServak();
signals:
    void downloadProgress(qint64, qint64);
    void done(const QUrl&, const QByteArray&);
    void error();

private slots:
    void slotFinished(QNetworkReply*);
};

#endif // DOWNLOADER

