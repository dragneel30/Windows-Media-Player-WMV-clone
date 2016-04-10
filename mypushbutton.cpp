#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget* parent)
    : QPushButton(parent)
{

}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
     if ( e->button() == Qt::LeftButton )
     {
         if ( text() == "Pause" )
         {
             emit clickedToPause();
             setText("Play");
         }
         else if ( text() == "Play" )
         {
             emit clickedToResume();
             setText("Pause");
         }
         else if ( text() == "Muted" )
         {
             emit clickedToSetMuted(false);
             setText("Unmuted");
         }
         else if ( text() == "Unmuted" )
         {
             emit clickedToSetMuted(true);
             setText("Muted");
         }
         else if ( text() == "Shuffled On" )
         {
             emit clickedToSetShuffled(false);
             setText("Shuffled Off");
         }
         else if ( text() == "Shuffled Off")
         {
             emit clickedToSetShuffled(true);
             setText("Shuffled On");
         }
         else if ( text() == "Repeat Off" )
         {
             emit clickedToSetRepeated(true);
             setText("Repeat On");
         }
         else if ( text() == "Repeat On" )
         {
             emit clickedToSetRepeated(false);
             setText("Repeat Off");
         }

     }
}




