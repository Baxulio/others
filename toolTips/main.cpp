#include "tooltip.h"
#include <QApplication>
#include <QLabel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToolTip w;
    w.setToolTip("<H1><font color='red'>Zdarova Chuvak</H1>");
    w.resize(500,500);

    w.show();

   // QLabel yes("Press ? ))xaxaxax",0, Qt::WindowContextHelpButtonHint | Qt::WindowCloseButtonHint);
   // yes.setWhatsThis("<I>You're the best guy</I><br><br><B>Yes I know. Ich liebe dich! xaxaxaxaxaxa</B>");

   // yes.show();
    return a.exec();
}
