#ifndef YES_H
#define YES_H

#include <QWidget>
#include "ui_xa.h"
class yes : public QWidget, public Ui::MyForm
{
    Q_OBJECT

public:
    yes(QWidget *parent = 0);
    ~yes();
public slots:
    void slotReset();
};

#endif // YES_H
