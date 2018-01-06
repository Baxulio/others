#include "turtleworkarea.h"

TurtleWorkArea::TurtleWorkArea(QWidget *parent)
    : QWidget(parent)
{
    m_pTurtle = new turtle;
    m_pTurtle->setFixedSize(400,400);

    m_ptxt = new QTextEdit;

    QComboBox *pcbo = new QComboBox;
    QStringList lst;

    lst<<"Haus vom Nikolaus"<<"Curly"<<"Circle"<<"Fantasy";
    pcbo->addItems(lst);

    connect(m_ptxt, SIGNAL(textChanged()), SLOT(slotApplyCode(int)));
    connect(pcbo,SIGNAL(activated(int)),SLOT(slotApplyCode(int)));
    slotApplyCode(0);

    QScriptValue scriptTurtle=m_scriptEngine.newQObject(m_pTurtle);
    m_scriptEngine.globalObject().setProperty("turtle", scriptTurtle);

    QPushButton *pcmd=new QPushButton("&Evaluate");
    connect(pcmd, SIGNAL(clicked(bool)), SLOT(slotEvaluate()));

    QGridLayout *pg=new QGridLayout;
    pg->addWidget(pcbo,0,0);
    pg->addWidget(m_ptxt,1,0);
    pg->addWidget(m_pTurtle,0,1,2,1);
    pg->addWidget(pcmd,2,0,1,2);
    setLayout(pg);
}
void TurtleWorkArea::slotEvaluate()
{
    QScriptValue result=m_scriptEngine.evaluate(m_ptxt->toPlainText());
    if (result.isError()) {
        QMessageBox::critical(0,"Evaluating Error", result.toString(),QMessageBox::Yes);
    }
}
void TurtleWorkArea::slotApplyCode(int n)
{
    QString strCode;
    switch(n){
    case 0:
        strCode="var k=100;\n"
                "turtle.reset();\n"
                "turtle.right(90);\n"
                "turtle.back(-k);\n"
                "turtle.left(90);\n"
                "turtle.forward(k);\n"
                "turtle.left(30);\n"
                "turtle.forward(k);\n"
                "turtle.left(120);\n"
                "turtle.forward(k);\n"
                "turtle.left(30);\n"
                "turtle.forward(k);\n"
                "turtle.left(135);\n"
                "turtle.forward(Math.sqrt(2)*k);\n"
                "turtle.left(135);\n"
                "turtle.forward(k);\n"
                "turtle.left(135);\n"
                "turtle.forward(Math.sqrt(2)*k);\n";
        break;
    case 1:
        strCode="turtle.reset();\n"
                "for(i=0;i<2;++i){\n"
                "   for(j=0;j<100;++j){\n"
                "       turtle.forward(15);\n"
                "       turtle.left(100-j);\n"
                "   }\n"
                "   turtle.right(180);\n"
                "}";
        break;
    case 2:
        strCode="turtle.circle=function()\n"
                "{\n"
                "   for(var i=0;i<360;++i){\n"
                "       this.forward(1);\n"
                "       this.left(1);\n"
                "   }\n"
                "}\n"
                "turtle.reset();\n"
                "turtle.circle();\n";
        break;
   default:
        strCode="turtle.reset();\n"
                "for(i=0;i<200;++i){\n"
                "   turtle.forward(i*2);\n"
                "   turtle.left(91);\n"
                "}";
    }
    m_ptxt->setPlainText(strCode);
}

TurtleWorkArea::~TurtleWorkArea()
{

}
