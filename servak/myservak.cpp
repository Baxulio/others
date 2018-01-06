#include <myservak.h>
GUI::GUI(QWidget *parent):QWidget(parent)
{
    pms = new MyServak(this);
    pprb = new QProgressBar;
    ple = new QLineEdit;
    ppb = new QPushButton;

    QString link="http://wallpart.com/adder/preview/pornstar-10913-48-print-poster-591315260.jpg";
     ple->setText(link);
    connect(ppb, SIGNAL(clicked(bool)), SLOT(slotGo()));
    connect(pms, SIGNAL(downloadProgress(qint64,qint64)),this, SLOT(slotDownloadProgress(qint64,qint64)));
    connect(pms,SIGNAL(done(QUrl,QByteArray)),this,SLOT(slotDone(QUrl,QByteArray)));

    QGridLayout *pgl = new QGridLayout;
    pgl->addWidget(ple,0,0);
    pgl->addWidget(ppb,0,1);
    pgl->addWidget(pprb,1,0,1,1);

    setLayout(pgl);
}
void GUI::slotGo()
{
    pms->download(QUrl(ple->text()));
}
void GUI::slotDownloadProgress(qint64 nRecieved, qint64 nTotal)
{
    if(nTotal<=0)
    {
        slotError();
        return;
    }
    pprb->setValue(100*nRecieved/nTotal);
}
void GUI::slotDone(const QUrl& url, const QByteArray& ba)
{
    QFile file(url.path().section('/',-1));
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(ba);
        file.close();

        if(file.fileName().endsWith(".jpg") || file.fileName().endsWith(".png"))
        {
            showPic(file.fileName());
        }
    }
}
void GUI::showPic(const QString &str)
{
    QPixmap pix(str);
    pix = pix.scaled(pix.size()/3, Qt::IgnoreAspectRatio,Qt::SmoothTransformation);

    QLabel *plbl = new QLabel;
    plbl->setPixmap(pix);
    plbl->setFixedSize(pix.size());
    plbl->show();
}
void GUI::slotError()
{
    QMessageBox::critical(0,tr("Error"),tr("An error while download is occured"));

}
