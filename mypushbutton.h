#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QMouseEvent>
#include <QMediaPlayer>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QWidget* parent = 0);
    void mouseReleaseEvent(QMouseEvent*);
signals:
    void clickedToPause();
    void clickedToResume(); // separated from pause for understandability
    void clickedToSetMuted(bool); // for muting and unmuting
    void clickedToSetShuffled(bool); // for shuffling and unshuffling
    void clickedToSetRepeated(bool); // for setting repeated or nah
};

#endif // MYPUSHBUTTON_H
