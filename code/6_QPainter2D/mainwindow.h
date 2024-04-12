#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QtSvg/QSvgGenerator>

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
    //重载父类的函数
    virtual void paintEvent(QPaintEvent* event);
    //用于保存SVG
    void paintAll(QSvgGenerator* generator = 0);

private slots:
    void on_actionSave_as_AVG_triggered();

private:
    Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
