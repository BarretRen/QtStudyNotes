#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <myclass.h>
#include <QtDebug>
#include <QGraphicsBlurEffect>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //跟踪鼠标设置
    this->setMouseTracking(true);
    ui->centralwidget->setMouseTracking(true);
    //将mainwindow新添加的signal与自定义类的slot函数绑定
    //    MyClass* myclass = new MyClass;
    //    connect(this, &MainWindow::doNow, myclass, &MyClass::doSomething);
    connect(this, &MainWindow::doNow, []()
    {
        QMessageBox::information(nullptr, "Hello", "MyClass slot function is called");
    });
    //设置logo的图形效果
    QGraphicsBlurEffect* blur = new QGraphicsBlurEffect();
    blur->setBlurRadius(8);
    ui->logo->setGraphicsEffect(blur);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginButton_clicked()
{
    emit doNow();//触发doNow signal
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    qDebug() << " mouse position" << event->pos();
}
