#include "myslider.h"

MySlider::MySlider(QWidget *parent)
    :QSlider(parent)
{
}

MySlider::~MySlider()
{
}

void MySlider::mouseReleaseEvent(QMouseEvent *e)
{
    if ( e->button() == Qt::LeftButton )
    {
        emit positionSkipped(value());
        setSliderDown(false);
    }
}

void MySlider::c_setRange(qint32 min, qint32 max)
{
    setRange(min,max);
    setValue(0);
}

void MySlider::movePosition(qint64 position)
{
    if ( !isSliderDown() && value() < maximum() )
    {
        setValue(position);
    }
    else if ( !isSliderDown() && value() >= maximum() )
    {
        emit trackFinished();
    }
}










