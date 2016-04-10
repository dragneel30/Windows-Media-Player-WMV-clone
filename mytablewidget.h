#ifndef MYTABLEWIDGET_H
#define MYTABLEWIDGET_H

#include <QTableWidget>
#include <QStringList>
#include <QVector>
class MyTableWidget : public QTableWidget
{
public:
    MyTableWidget(QWidget* parent=0);
    void fillContent(const QString&,int);
    void resetTable();
};


#endif // MYTABLEWIDGET_H
