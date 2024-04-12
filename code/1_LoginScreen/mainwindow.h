#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    //添加成员函数用于函数调用
    void mouseMoveEvent(QMouseEvent* event);

signals:
    void doNow();//添加一个新的signal信号

private slots:
    void on_loginButton_clicked();

private:
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
