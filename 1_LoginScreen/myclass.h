#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QMessageBox>

class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject* parent = nullptr);

signals:
public slots:
    void doSomething()//添加自定义的slot函数，用于处理事件
    {
        QMessageBox::information(nullptr, "Hello", "MyClass slot function is called");
    }
};

#endif // MYCLASS_H
