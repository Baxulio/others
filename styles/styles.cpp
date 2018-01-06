#include "styles.h"

styles::styles(QWidget *parent)
    : QWidget(parent)
{
    QComboBox *pcb = new QComboBox;
    QSpinBox *psb = new QSpinBox;
    QSlider * psld = new QSlider(Qt::Horizontal);
    QRadioButton *prb = new QRadioButton("&Radio Button");
    QCheckBox *pchb = new QCheckBox("&Check Box");
    QPushButton *ppb = new QPushButton("&Push Button");
    QTableWidget *pt = new QTableWidget(3,5,this);
    pcb->addItems(QStyleFactory::keys());

    connect(pcb, SIGNAL(activated(QString)), SLOT(slotChangeStyle(QString)));

    QVBoxLayout* pvbl = new QVBoxLayout;
    pvbl->addWidget(pcb);
    pvbl->addWidget(psb);
    pvbl->addWidget(psld);
    pvbl->addWidget(prb);
    pvbl->addWidget(pchb);
    pvbl->addWidget(ppb);
    pvbl->addWidget(pt);

    setLayout(pvbl);
}
void styles::slotChangeStyle(const QString &str)
{
    QStyle *pstyle = QStyleFactory::create(str);
    QApplication::setStyle(pstyle);
}

styles::~styles()
{

}
