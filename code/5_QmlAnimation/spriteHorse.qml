import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true;
    width: 420;
    height: 380;
    Rectangle {
        anchors.fill: parent;
        color: "white";
    }

    AnimatedSprite {
        id: sprite;
        width: 128;
        height: 128;
        source: "qrc:/horse_1.png";
        frameCount: 11; //帧数
        frameWidth: 128;
        frameHeight: 128;
        frameRate: 25;
        loops: Animation.Infinite;
        running: true;

        NumberAnimation {//添加平移动画，x坐标移动
            target: sprite;
            property: "x";
            from: -128;
            to: 512;
            duration: 3000;
            loops: Animation.Infinite;
            running: true;
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {//控制sprite的暂停
            if (sprite.paused)
                sprite.resume();
            else
                sprite.pause();
        }
    }
}
