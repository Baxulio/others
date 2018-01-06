#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include <QWidget>
#include <QtWidgets>
#include <QtWebKitWidgets>

class QLineEdit;
class QWebView;
class QPushButton;

class WebBrowser : public QWidget
{
    Q_OBJECT

private:
    QLineEdit *plineEdit;
    QWebView *pwebView;
    QPushButton *pBack;
    QPushButton *pForward;
public:
    WebBrowser(QWidget *parent = 0);
    ~WebBrowser();
private slots:
    void slotGo();
    void slotFinished(bool);
};

#endif // WEBBROWSER_H
