import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: myWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    //添加canvas画布
    Canvas{
        id: myCanvas;
        width: myWindow.width;
        height: myWindow.height;
        //在画布上画图
        onPaint: {
            //基本属性设置
            var context = getContext('2d')
            context.fillStyle = 'white'
            context.fillRect(0, 0, width, height)
            context.lineWidth = 2
            context.strokeStyle = 'black'
            //画交叉线
            context.beginPath()
            context.moveTo(50, 50)
            context.lineTo(100, 100)
            context.closePath()
            context.stroke()

            context.beginPath()
            context.moveTo(100, 50)
            context.lineTo(50, 100)
            context.closePath()
            context.stroke()
            //画三角形
            context.lineWidth = 4
            context.strokeStyle = "red"
            context.fillStyle = "salmon"
            context.beginPath()
            context.moveTo(50,150)
            context.lineTo(150,150)
            context.lineTo(50,250)
            context.closePath()
            context.fill()
            context.stroke()
            //画圆
            context.strokeStyle = "blue"
            context.fillStyle = "steelblue"
            var pi = 3.141592653589793
            context.beginPath()
            context.arc(220, 200, 60, 0, 2 * pi, true)//2*pi表示整圆，pi是半圆
            context.closePath()
            context.fill()
            context.stroke()
            //画图片
            context.drawImage("qrc:/tux.png", 280, 10, 150, 174)
        }
        onImageLoaded: requestPaint();
    }
}
