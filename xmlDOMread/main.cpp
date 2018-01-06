
#include <QtXml>

void reverseNode(const QDomNode &node)
{
    QDomNode domNode = node.firstChild();
    while(!domNode.isNull())
    {
        if(domNode.isElement())
        {
            QDomElement domElement = domNode.toElement();
            if(!domElement.isNull())
            {
                if(domElement.tagName() == "contact")
                {
                    qDebug()<<"Attr: "<<domElement.attribute("number", "");
                }
                else qDebug()<<"TagName: "<<domElement.tagName()<<"\tText: "<<domElement.text();
            }
        }
        reverseNode(domNode);
        domNode = domNode.nextSibling();
    }
}

int main()
{
    QDomDocument domDoc;
    QFile file("addressbook.xml");

    if(file.open(QIODevice::ReadOnly))
    {
        if(domDoc.setContent(&file))
        {
            QDomElement domElement = domDoc.documentElement();
            reverseNode(domElement);
        }
        file.close();
    }
    return 0;
}
