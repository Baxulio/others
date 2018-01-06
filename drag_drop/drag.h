#ifndef DRAG_H
#define DRAG_H

#include <QtWidgets>

class drag : public QLabel
{
    Q_OBJECT

private:
    QPoint m_ptDragPos;

    void startDrag()
    {
        QMimeData* pMimeData = new QMimeData;
        pMimeData->setText(text());

        QDrag *pDrag = new QDrag(this);
        pDrag->setMimeData(pMimeData);
        pDrag->setPixmap(QPixmap(":/acs.png"));
        pDrag->exec();
    }
protected:
    virtual void mouseMoveEvent(QMouseEvent *pe)
    {
        if(pe->buttons() & Qt::LeftButton)
        {
            int distance = (pe->pos() - m_ptDragPos).manhattanLength();
            if(distance > QApplication::startDragDistance())
            {
                startDrag();
            }
        }
        QWidget::mouseMoveEvent(pe);
    }
    virtual void mousePressEvent(QMouseEvent *ev)
    {
        if(ev->button() == Qt::LeftButton)
        {
            m_ptDragPos=ev->pos();
        }
        QWidget::mousePressEvent(ev);
    }

public:
    drag(QWidget *parent = 0):QLabel("This is draggable text", parent)
    {

    }

    ~drag();
};

#endif // DRAG_H
