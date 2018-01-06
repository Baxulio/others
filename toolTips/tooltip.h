#ifndef TOOLTIP_H
#define TOOLTIP_H

#include <QWidget>
#include <QtWidgets>
class ToolTip : public QWidget
{
    Q_OBJECT
private:
    QLabel *ptoolTip;
protected:
    virtual bool event(QEvent *ev)
    {
        if(ev->type()==QEvent::ToolTip)
        {
            QHelpEvent *phelp=static_cast<QHelpEvent*>(ev);
            ptoolTip->move(phelp->globalPos());
            ptoolTip->setText(toolTip());



            ptoolTip->show();
            QTimer::singleShot(10000,ptoolTip,SLOT(hide()));

            return true;
        }
        return QWidget::event(ev);
    }

public:
    ToolTip(QWidget *parent = 0):QWidget(parent)
    {
        ptoolTip=new QLabel(this);
        ptoolTip->setPixmap(QPixmap(":/acs1.png"));
        ptoolTip->setWindowFlags(Qt::ToolTip);
    }

    ~ToolTip();
};

#endif // TOOLTIP_H
