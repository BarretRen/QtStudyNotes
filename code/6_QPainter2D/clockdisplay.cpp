#include "clockdisplay.h"
#include "ui_clockdisplay.h"
//时钟实现

ClockDisplay::ClockDisplay(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::ClockDisplay)
{
    ui->setupUi(this);
    //通过timer，不断调用paintEvent
    QTimer* timer = new QTimer(this);
    timer->start(1000);//timer duration
    connect(timer, &QTimer::timeout, this, &ClockDisplay::updateUI);
}

ClockDisplay::~ClockDisplay()
{
    delete ui;
}

void ClockDisplay::updateUI()
{
    this->update();
}
void ClockDisplay::paintEvent(QPaintEvent* event)
{
    //定义表盘指针
    static const QPoint hourHand[3] =
    {
        QPoint(4, 4),
        QPoint(-4, 4),
        QPoint(0, -40)
    };
    static const QPoint minuteHand[3] =
    {
        QPoint(4, 4),
        QPoint(-4, 4),
        QPoint(0, -70)
    };
    static const QPoint secondHand[3] =
    {
        QPoint(2, 2),
        QPoint(-2, 2),
        QPoint(0, -90)
    };
    //创建Qpainter
    int side = qMin(width(), height());
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);//防锯齿
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 250.0, side / 250.0);
    //绘制表盘
    for (int i = 0; i < 60; ++i)
    {
        if ((i % 5) != 0)
        {
            painter.drawLine(92, 0, 96, 0);
        }
        else
        {
            painter.drawLine(86, 0, 96, 0);
        }
        painter.rotate(6.0);//360 / 60
    }
    //绘制多边形
    QTime time = QTime::currentTime();
    painter.save();
    painter.rotate((time.hour() * 360) / 12);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();
    painter.save();

    painter.rotate((time.minute() * 360) / 60);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::blue);
    painter.drawConvexPolygon(minuteHand, 3);
    painter.restore();

    painter.save();
    painter.rotate((time.second() * 360) / 60);
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::green);
    painter.drawConvexPolygon(secondHand, 3);
    painter.restore();
}
