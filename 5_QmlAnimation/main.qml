import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Animation")
    Rectangle{
        id:background;
        anchors.fill: parent;
        color: "blue";
//        SequentialAnimation on color {
//            ColorAnimation { to: "yellow"; duration: 1000 }
//            ColorAnimation { to: "red"; duration: 1000 }
//            ColorAnimation { to: "blue"; duration: 1000 }
//            loops: Animation.Infinite;
//        }
        //add state machine
        states: [
            State {
                name: "PRESSED"
                PropertyChanges { target: background; color: "blue" }
            },
            State {
                name: "RELEASED"
                PropertyChanges { target: background; color: "red" }
            }
        ]
        //add animation transition
        transitions: [
            Transition {
                from: "PRESSED"
                to: "RELEASED"
                ColorAnimation { target: background; duration: 1000}
            },
            Transition {
                from: "RELEASED"
                to: "PRESSED"
                ColorAnimation { target: background; duration: 1000}
            }
        ]
        //add mouse area
        MouseArea{
            anchors.fill: parent;
            onPressed: background.state = "PRESSED";
            onReleased: background.state = "RELEASED";
        }
    }
    Text {
        id: txt;
        text: qsTr("Hello World");
        anchors.centerIn: parent;
        color: "white";
        font.pointSize: 15;
        SequentialAnimation on opacity {
            NumberAnimation { to: 0.0; duration: 1000}
            NumberAnimation { to: 1.0; duration: 1000}
            loops: Animation.Infinite;
        }
    }
}
/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
