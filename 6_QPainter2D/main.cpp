#include "mainwindow.h"
#include <clockdisplay.h>
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    //    MainWindow w;
    //    w.show();
    ClockDisplay c;
    c.show();
    return a.exec();
}
