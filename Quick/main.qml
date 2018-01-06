import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    MainForm {
        anchors.fill: parent
        Item {
            width:1600
            height:1200
            Image {
                id: s0
                source: "images/слой_0.png"
                x: 0
                y: 0
                opacity: 1
            }
            Image {
                id: s0kop
                visible: false
                source: "images/слой_0_копия.png"
                x: 0
                y: 0
                opacity: 1
            }
            Image {
                id: pr4k
                visible: false
                source: "images/прямоугольник_4_копия.png"
                x: 49
                y: 321
                opacity: 1
            }
            Image {
                id: s1
                visible: false
                source: "images/слой_1.png"
                x: 0
                y: 204
                opacity: 1
            }
            Image {
                id: p4k2
                visible: false
                source: "images/прямоугольник_4_копия_2.png"
                x: 372
                y: 328
                opacity: 1
            }
            Image {
                id: divcenter
                source: "images/divcenter.png"
                x: 396
                y: 328
                opacity: 1
            }
            Image {
                id: divleft
                source: "images/divleft.png"
                x: 62
                y: 328
                opacity: 1
            }
            Image {
                id: divright
                source: "images/divright.png"
                x: 1178
                y: 328
                opacity: 1
            }
            Image {
                id: foot
                source: "images/foot.png"
                x: -22
                y: 906
                opacity: 1
            }
            Image {
                id: menu
                source: "images/menu.png"
                x: -1
                y: 251
                opacity: 1
            }
            Image {
                id: header
                source: "images/header.png"
                x: 60
                y: 8
                opacity: 1
            }
        }

    }

    MessageDialog {
        id: messageDialog
        title: qsTr("May I have your attention, please?")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }
}
