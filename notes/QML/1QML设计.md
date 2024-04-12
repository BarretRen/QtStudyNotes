QML类似与JavaScript，可以用来编写Qt Quick组件和样式（**简直就是html+css+js）**，不需要C++参与界面样式设置。在QT5中首次出现，是当前流行的QT GUI绘制方式。

# 1 QtQuick UI file
创建新文件，选择创建QtQuick UI文件，该文件值包含布局，不包含外面的窗体。在该文件设置好UI的样式和组件之后，可以作为一个完整的组件include到主窗体中：

![image.png](.assets/1600446478305-1080f36b-e9f0-4fad-9b4b-af14641fa4c2.png)

```javascript
import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 800
    height: 600
    title: qsTr("My Login From")

    LoginFrom{ /*loginFrom是一个单独的UI文件，这里被作为组件include进来*/
        anchors.fill: parent /*在主窗口中的边距锚点*/
    }
}
```
LoginFrom UI文件后缀为**ui.qml**，表示这是一个QtQuick UI文件，里面的布局可以作为一个单独的组件被其他**qml**文件使用。LoginForm.ui.qml的内容截取如下：
```javascript
ectangle {
    id: window

    width: 800
    height: 600

    Image {
        id: background
        anchors.fill: parent
        source: "login_bg.png"
    }
	Text {
        id: dateTime
        color: "#ffffff"
        text: qsTr("Monday, 26-10-2015 3:14 PM")
        anchors.top: parent.top
        anchors.topMargin: 26
        anchors.left: parent.left
        anchors.leftMargin: 26
        font.pixelSize: 14
    }
  ...
}
```

# 2 C++代码中控制样式
所有的QML对象类型都是源自QObject类型，因此,QML引擎可以使用Qt元对象系统动态的实例化QML对象，并获取所创建对象的属性与方法。也就是说一旦创建了QML对象，就可以使用C++获取它的属性、函数与信号处理。
假设存在一个名为MyItem.qml的文件，内容如下
```javascript
import QtQuick 2.12

Item {
    width: 100; height: 100
  
   Image {
        id: background
        anchors.fill: parent
        source: "login_bg.png"
    }
}
```
在C++中，QML文档可以使用 `QQmlComponent`或 `QQuickView`来加载。

- 使用QQmlComponent 需要调用`QQmlComponent::create()`创建一个QObject 实例。并在使用完后delete。
- 使用QQuickView会自动的创建一个QObject 实例，可以通过`view.rootObject()`来获取。

加载方法如下：
```cpp
// Using QQmlComponent
QQmlEngine engine;
QQmlComponent component(&engine, QUrl::fromLocalFile("MyItem.qml"));
QObject* object = component.create(); 
...
delete object;

// Using QQuickView
QQuickView view;
view.setSource(QUrl::fromLocalFile("MyItem.qml"));
view.show();
QObject* object = view.rootObject();

//获取QObect后，通过name获取qml对象，并设置属性
QObject* img = object->findChild<QObject*>("background");
if (img)
    img->setProperty("color", "red");
```

