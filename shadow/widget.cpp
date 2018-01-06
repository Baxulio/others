#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsDropShadowEffect>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect *s=new QGraphicsDropShadowEffect(this);
    s->setBlurRadius(10);
    s->setOffset(0);

    ui->label->setGraphicsEffect(s);

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

}

Widget::~Widget()
{
    delete ui;
}
