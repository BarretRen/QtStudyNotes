#ifndef CLOCKDISPLAY_H
#define CLOCKDISPLAY_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QPainter>

namespace Ui
{
class ClockDisplay;
}

class ClockDisplay : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClockDisplay(QWidget* parent = nullptr);
    ~ClockDisplay();

    virtual void paintEvent(QPaintEvent* event);
    void updateUI();

private:
    Ui::ClockDisplay* ui;
};

#endif // CLOCKDISPLAY_H
