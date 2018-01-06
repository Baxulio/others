import QtQuick 2.4
import QtQuick.Controls 1.3

ApplicationWindow {
    title: qsTr("Hello World")
    width: 222
    height: 222
    opacity: 0.8
    visible: true

    Rectangle{
        width: 100
        height: 100
        //        x: 0
        //        y: 0
        id: rect
        state: "State1"
        color: "magenta"
        Text {
            anchors.centerIn: parent
            text: "Click Me!"
        }
        MouseArea{
            anchors.fill: rect
            onClicked: rect.state=rect.state=="State1"?"State2":"State1"
        }

        states: [
            State {
                name: "State1"
                PropertyChanges {

                    target: rect
                    color: "green"
                    x: 0
                    y: 0
                }
            },
            State {
                name: "State2"
                PropertyChanges {
                    target: rect
                    color: "Red"
                    x: 200
                    y: 200
                }
            }
        ]
        transitions: [
            Transition {
                from: "State1"
                to: "State2"
                ParallelAnimation{
                    PropertyAnimation{
                        target: rect
                        properties: "x,y"
                        easing.type: Easing.InCirc
                        duration: 1000
                    }
                    PropertyAnimation{
                        target: rect
                        properties: "color"
                        easing.type: Easing.InCirc
                        duration: 1000
                    }
                }


            },
            Transition {
                from: "State2"
                to: "State1"
                ParallelAnimation{
                    PropertyAnimation{
                        target: rect
                        properties: "x,y"
                        easing.type: Easing.InCirc
                        duration: 1000
                    }
                    PropertyAnimation{
                        target: rect
                        properties: "color"
                        easing.type: Easing.InCirc
                        duration: 1000
                    }
                }

            }
        ]
    }
}
