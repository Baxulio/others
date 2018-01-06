import QtQuick 2.0

BorderImage {
    id: bi
    property alias text: txt.text
    signal clicked;

    source: "qrc:/../../../12301521_1655503134738983_6326797348517269752_n.jpg"
    width: txt.width+15; height: txt.height+15
    border.left: 5; border.top: 5
    border.right: 5; border.bottom: 5

    Text {
        id: txt
        color: "white"
        anchors.centerIn: parent
    }
    MouseArea{
        anchors.fill: parent
        onClicked: parent.clicked();
        onPressed: parent.source="qrc:/../../../image.jpg"
        onReleased: parent.source="qrc:/../../../12301521_1655503134738983_6326797348517269752_n.jpg"
    }
}
