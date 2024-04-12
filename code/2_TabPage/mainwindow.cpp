#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstyle.h>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //为控件新加属性，并设置值，类似JS设置CSS
    ui->button1->setProperty("pagematches", true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    //set all buttons to false
    ui->button1->setProperty("pagematches", false);
    ui->button2->setProperty("pagematches", false);
    ui->button3->setProperty("pagematches", false);

    //set true according to the tab index
    if (index == 0)
    {
        ui->button1->setProperty("pagematches", true);
    }
    else if (index == 1)
    {
        ui->button2->setProperty("pagematches", true);
    }
    else
    {
        ui->button3->setProperty("pagematches", true);
    }

    //refresh the button style
    ui->button1->style()->polish(ui->button1);
    ui->button2->style()->polish(ui->button2);
    ui->button3->style()->polish(ui->button3);
}
