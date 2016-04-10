#include "mylineedit.h"

#include <QKeyEvent>
#include <QDebug>
#include <QMouseEvent>
MyLineEdit::MyLineEdit(QWidget *parent)
    :QLineEdit(parent),text_before_modified(text())
{
    connect(this,SIGNAL(editingFinished()),this,SLOT(emitter()));
}

MyLineEdit::~MyLineEdit()
{

}

void MyLineEdit::mousePressEvent(QMouseEvent* e)
{
    if ( e->button() == Qt::LeftButton )
        selectAll();
}

void MyLineEdit::enterEvent(QEvent*)
{
    setFrame(true);
}

void MyLineEdit::leaveEvent(QEvent*)
{
    setFrame(false);
}

void MyLineEdit::emitter()
{
     if ( !text().isEmpty() )
     {
         emit editingFinishedEmitted(text(),text_before_modified);
         text_before_modified = text();
     }
}



