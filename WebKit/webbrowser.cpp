#include "webbrowser.h"

WebBrowser::WebBrowser(QWidget *parent)
    : QWidget(parent)
{
    plineEdit = new QLineEdit("http://fb.com");
    pwebView = new QWebView;
    pBack = new QPushButton("<");
    pForward = new QPushButton(">");

    pBack->setEnabled(false);
    pForward->setEnabled(false);

    QProgressBar *pProgBar = new QProgressBar;
    QPushButton *go = new QPushButton("&Go");
    QPushButton *stop = new QPushButton("&Stop");
    QPushButton *refresh = new QPushButton("&Refresh");

    connect(go,SIGNAL(clicked(bool)),SLOT(slotGo()));
    connect(plineEdit,SIGNAL(returnPressed()),SLOT(slotGo()));
    connect(pBack,SIGNAL(clicked(bool)),pwebView,SLOT(back()));
    connect(pForward,SIGNAL(clicked(bool)),pwebView,SLOT(forward()));
    connect(refresh,SIGNAL(clicked(bool)),pwebView,SLOT(reload()));
    connect(stop,SIGNAL(clicked(bool)),pwebView,SLOT(stop()));
    connect(pwebView, SIGNAL(loadProgress(int)), pProgBar,SLOT(setValue(int)));
    connect(pwebView, SIGNAL(loadFinished(bool)),SLOT(slotFinished(bool)));

    QHBoxLayout *hl = new QHBoxLayout;

    hl->addWidget(pBack);
    hl->addWidget(pForward);
    hl->addWidget(stop);
    hl->addWidget(refresh);
    hl->addWidget(plineEdit);
    hl->addWidget(go);

    QVBoxLayout *vl = new QVBoxLayout;
    vl->addLayout(hl);
    vl->addWidget(pwebView);
    vl->addWidget(pProgBar);

    setLayout(vl);

    slotGo();
}
void WebBrowser::slotGo()
{
    if(
            !plineEdit->text().startsWith("ftp://")
         && !plineEdit->text().startsWith("http://")
         && !plineEdit->text().startsWith("gopher://")
       )
    {
        plineEdit->setText("http://"+plineEdit->text());
    }
    pwebView->load(QUrl(plineEdit->text()));
}
void WebBrowser::slotFinished(bool ok)
{
    if (!ok)
    {
        pwebView->setHtml("<CENTER>An error occured while loading the page :(");
    }
    plineEdit->setText(pwebView->url().toString());

    pBack->setEnabled(pwebView->page()->history()->canGoBack());
    pForward->setEnabled(pwebView->page()->history()->canGoForward());
}

WebBrowser::~WebBrowser()
{

}
