import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QML Animation")
    Rectangle{
        id:myBox;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.verticalCenter: parent.verticalCenter;
        width: 50;
        height: 50;
        color: "blue";
        ParallelAnimation {
            ColorAnimation {
                target: myBox
                property: "color"
                from: "forestgreen"
                to: "lightsteelblue";
                duration: 1000
            }
            ScaleAnimator {
                target: myBox
                from: 2
                to: 1
                duration: 1000
            }
            running: true
        }
    }
}
