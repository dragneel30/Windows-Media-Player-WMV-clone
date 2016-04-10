#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    MyLineEdit(QWidget* parent = 0);
    ~MyLineEdit();
    void mousePressEvent(QMouseEvent*);
    virtual void enterEvent(QEvent*);
    virtual void leaveEvent(QEvent*);
public slots:
    void emitter();
signals:
    void editingFinishedEmitted(QString,QString);
private:
    QString text_before_modified;
};






#endif // MYLINEEDIT_H
