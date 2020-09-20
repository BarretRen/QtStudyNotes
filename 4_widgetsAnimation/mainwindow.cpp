#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QParallelAnimationGroup>
//state machine头文件
#include <QStateMachine>
#include <QEventTransition>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //1. 使用animation object为button添加动画
    QPropertyAnimation* animation1 = new QPropertyAnimation(ui->pushButton, "geometry");
    animation1->setDuration(3000);
    animation1->setStartValue(ui->pushButton->geometry());
    animation1->setEndValue(QRect(50, 200, 100, 50));

    QPropertyAnimation* animation2 = new QPropertyAnimation(ui->pushButton2, "geometry");
    animation2->setDuration(3000);
    animation2->setStartValue(ui->pushButton2->geometry());
    animation2->setEndValue(QRect(150, 200, 100, 50));
    //添加easing curve
    QEasingCurve curve;
    curve.setType(QEasingCurve::Linear);
    curve.setAmplitude(1.00);
    curve.setOvershoot(1.70);
    curve.setPeriod(0.30);
    animation1->setEasingCurve(curve);
    animation2->setEasingCurve(curve);
    //创建动画组
    QParallelAnimationGroup* group = new QParallelAnimationGroup;
    group->addAnimation(animation1);
    group->addAnimation(animation2);
    group->start();

    //===============================================================================
    //2.使用state machine实现动画
    QStateMachine* machine = new QStateMachine(this);
    QState* s1 = new QState();//创建一个状态
    s1->assignProperty(ui->label1, "text", "Current state: 1");//此状态下控件的属性
    s1->assignProperty(ui->pushButton3, "geometry", QRect(400, 200, 100, 50));
    QState* s2 = new QState();
    s2->assignProperty(ui->label1, "text", "Current state: 2");
    s2->assignProperty(ui->pushButton3, "geometry", QRect(600, 50, 140, 100));
    //绑定控件事件和状态
    QEventTransition* t1 = new QEventTransition(ui->changeState, QEvent::MouseButtonPress);
    //状态切换时添加动画，不能瞬间变过去
    t1->addAnimation(new QPropertyAnimation(ui->pushButton3, "geometry"));
    t1->setTargetState(s2);
    s1->addTransition(t1);
    QEventTransition* t2 = new QEventTransition(ui->changeState, QEvent::MouseButtonPress);
    t2->addAnimation(new QPropertyAnimation(ui->pushButton3, "geometry"));
    t2->setTargetState(s1);
    s2->addTransition(t2);
    //添加到state machine中
    machine->addState(s1);
    machine->addState(s2);
    machine->setInitialState(s1);//设置默认状态
    machine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

