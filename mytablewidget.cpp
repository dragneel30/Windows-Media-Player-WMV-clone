#include "mytablewidget.h"
#include <QDebug>

#include <QHeaderView>
#include <QMouseEvent>

MyTableWidget::MyTableWidget(QWidget *parent)
    :QTableWidget(parent)
{
    horizontalHeader()->setSectionsMovable(true);
    verticalHeader()->setSectionsMovable(true);
    setShowGrid(false);
    setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
    setRowCount(1);


}

void MyTableWidget::fillContent(const QString& str,int column)
{
    setItem(rowCount()-1,column,new QTableWidgetItem(str));
    if ( column == 11 )
    {
        setRowCount(rowCount()+1);
    }
}

void MyTableWidget::resetTable()
{
    clearContents();
    setRowCount(1);
}















