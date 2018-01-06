//#include "js.h"
#include <QtScript>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *wgt=new QWidget;
    QLineEdit *ptxt=new QLineEdit;
    ptxt->setObjectName("lineedit");

    QLabel *plbl1=new QLabel("1");
    plbl1->setObjectName("label1");

    QLabel *plbl2=new QLabel("2");
    plbl2->setObjectName("label2");

    QLabel *plbl3=new QLabel("3");
    plbl3->setObjectName("label3");

    QVBoxLayout *v=new QVBoxLayout;
    v->addWidget(ptxt);
    v->addWidget(plbl1);
    v->addWidget(plbl2);
    v->addWidget(plbl3);
    wgt->setLayout(v);

    wgt->show();

    //Script part oohhh yeah

   QScriptEngine scriptEngine;
   QFile file("script.js");
   if(file.open(QFile::ReadOnly))
   {
       QScriptValue scriptWgt = scriptEngine.newQObject(wgt);
       scriptEngine.globalObject().setProperty("wgt",scriptWgt);

       QScriptValue result = scriptEngine.evaluate(QLatin1String(file.readAll()));
       if(result.isError()){
           QMessageBox::critical(0,"Evaluating error", result.toString(),QMessageBox::Yes);
       }
   }
   else {
       QMessageBox::critical(0, "File open error", "Can't open the js", QMessageBox::Yes);
   }

    return a.exec();
}
