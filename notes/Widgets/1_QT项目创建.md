# 项目模板

在选择 Class information 时，有三种基类可以选择，基类奠定了 GUI 的样式：

- **QMainWindow**：主窗口类，主窗口具有主菜单栏、工具栏和状态栏。 类似于一般的应用程序的主窗口
- **QWidget**：是可视界面类的基类，也就是说 QMainWindow 类也是由 QWidget 继承封装而来。所以 QWidget 要比 QMainWindow 功能少一些
- **QDialog**：对话框类，建立一个对话框界面。比较少使用此项作为基类

**在嵌入式里一般不需要标题栏，状态栏等，所以常用的是 QWidget 基类。**

# 项目文件分类

- **\*.pro** 是项目管理文件，当加入了文件或者删除了文件， Qt Creator 会自动修改这个*.pro 文件。有时候需要打开这个*.pro 文件添加我们的设置项。
- **Header**分组，这个节点下存放的是项目内所有的头文件\*.h。
- **Source**分组，这个节点下存放的是项目内的所有 C++源码文件\*.cpp。
- **Forms**分组，这个节点下是存放项目内所有界面文件*.ui。 *.ui 文件由 XML 语言描述组成，编译时会生成相应的 cpp 文件。

​

## .pro 文件

.pro 文件是整个项目的管理文件，类似 Android 的 manifest 文件，主要分为以下几部分：

```
QT       += core gui--------------->支持的QT模块，根据需求添加

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11-------------->设置使用C++的标准

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

-------------->设置三个目录下的文件
SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

------------------->设置生成文件路径
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

```

## .ui 文件

ui 文件是 xml 类型，描述界面组件，不能手动编辑，需要在 designer 中进行修改。在编译时，会自动生成头文件，比如`mainwindow.ui`文件会编译生成`**ui_mainwindow.h**`头文件：

```cpp
class Ui_MainWindow
{
    //...
};

//UI空间的类被Cpp文件引用
namespace Ui {
    class MainWindow: public Ui_MainWindow {};
}
```

这个文件会在 mainwindow.cpp 中进行引用，用于初始化 ui 成员，这样在调用 show 的时候会自动应用 ui 文件设计的界面：

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"//引用ui生成的头文件

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)//初始化ui成员
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
```
