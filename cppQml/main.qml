import QtQuick 2.4
import QtQuick.Controls 1.2

ApplicationWindow{
    title: "imageBrightness"
    width: maximumWidth
    height: maximumHeight
    visible: true

    Column{
        anchors.fill: parent
        id: controls

        Image {
            anchors.centerIn: parent
            id: img
            source: "image://brightness/1.jpeg;"+sld.brightnessValue
        }
        Slider {
            id: sld
            width: img.width
            value: 0.75
            stepSize: 0.01
            property int brightnessValue: value*255-127
        }
        Text {
            id: t
            text: qsTr("<h1>Brighness: "+sld.brightnessValue+"</h>")
        }
    }
}
