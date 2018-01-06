#include "downloader.h"

MyServak::MyServak(QObject *parent)
    : QObject(parent)
{
    pacm=new QNetworkAccessManager(this);
    connect(pacm,SIGNAL(finished(QNetworkReply*)),this,SLOT(slotFinished(QNetworkReply*)));

}
void MyServak::download(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *pnr=pacm->get(request);

    connect(pnr,SIGNAL(downloadProgress(qint64,qint64)),this, SIGNAL(downloadProgress(qint64,qint64)));
}
void MyServak::slotFinished(QNetworkReply *pnr)
{
    if(pnr->error() != QNetworkReply::NoError)
    {
        emit error();
    }
    else
    {
        emit done(pnr->url(), pnr->readAll());
    }
    pnr->deleteLater();
}

MyServak::~MyServak()
{

}

