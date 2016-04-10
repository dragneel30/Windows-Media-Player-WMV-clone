#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QSlider>
#include <QMouseEvent>
#include <QDebug>
#include <QTimer>

class MySlider : public QSlider
{
    Q_OBJECT
public:
    MySlider(QWidget* parent = 0);
    ~MySlider();
    void mouseReleaseEvent(QMouseEvent*);
public slots:
    void c_setRange(qint32,qint32);
    void movePosition(qint64);
signals:
    void trackFinished();
    void positionSkipped(int);

};

#endif // MYSLIDER_H
