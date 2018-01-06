#ifndef DROP
#define DROP

#include <QtWidgets>

class drop : public QLabel
{
Q_OBJECT

protected:
    virtual void dragEnterEvent(QDragEnterEvent* ev)
    {
        if(ev->mimeData()->hasFormat("text/url-list"))
        {
            ev->acceptProposedAction();
        }
    }
    virtual void dropEvent(QDropEvent *ev)
    {
        QList<QUrl> urlList = ev->mimeData()->urls();
        QString str;
        foreach (QUrl url, urlList) {
            str+= url.toString()+"\n";
        }
        setText("Dropped: \n"+str);
    }
public:
    drop(QWidget* par=0): QLabel("Drop Area", par)
    {
        setAcceptDrops(true);

    }
};

#endif // DROP

