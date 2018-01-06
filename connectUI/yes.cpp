#include "yes.h"

yes::yes(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);
    connect(pReset, SIGNAL(clicked(bool)),SLOT(slotReset()));
}
void yes::slotReset()
{
    horizontalSlider->setValue(0);
}

yes::~yes()
{

}
