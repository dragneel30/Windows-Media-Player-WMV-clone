#include "mytreewidget.h"
#include <QDebug>
#include <QLineEdit>
#include <QMouseEvent>
#include <QMessageBox>
MyTreeWidget::MyTreeWidget(QWidget *parent)
    :QTreeWidget(parent), context_menu(new QMenu)
{
    connect(this,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this,SLOT(sendChildName(QTreeWidgetItem*,int)));
    connect(this,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this,SLOT(expandAll()));

    setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(contextMenu(QPoint)));
    context_menu = new QMenu;
    context_menu->addAction("Open",this,SLOT(open()));
    context_menu->addAction("Play",this,SLOT(play()));
    context_menu->addAction("Add to");
    context_menu->addSeparator();
    context_menu->addAction("Rename",this,SLOT(rename()));
    context_menu->addSeparator();
    context_menu->addAction("Delete",this,SLOT(del()));
    context_menu->addSeparator();
    context_menu->addAction("Open file location",this,SLOT(openFileLocation()));
    context_menu->addSeparator();
    context_menu->addAction("Customize navigation panel");


}

MyTreeWidget::~MyTreeWidget()
{

}

void MyTreeWidget::mouseDoubleClickEvent(QMouseEvent* e)
{
    if ( e->button() == Qt::LeftButton )
    {
        if ( !currentItem()->parent() )
        {
            if ( currentItem()->childCount() != 0 )
            {
                currentItem()->setExpanded(!currentItem()->isExpanded());
            }
        }
        else
        {
            if ( currentItem()->parent() == topLevelItem(1) )
            {
                emit clickedToSetCurrentPlaylist(currentItem()->text(0));
                emit clickedToClearMap();
            }
        }
    }
    else
        QTreeWidget::mouseDoubleClickEvent(e);
}

void MyTreeWidget::mousePressEvent(QMouseEvent* e)
{
    if ( e->button() == Qt::LeftButton )
    {
        QTreeWidget::mousePressEvent(e);
        emit clickedToMap(currentItem()->text(0));
    }

}



void MyTreeWidget::addChild(QString name)
{
    QTreeWidgetItem* child = new QTreeWidgetItem();
    child->setFlags(child->flags() | Qt::ItemIsEditable);
    child->setText(0,name);
    topLevelItem(1)->insertChild(0,child);
}

void MyTreeWidget::createChild()
{
    QTreeWidgetItem* new_child = new QTreeWidgetItem();
    last_item_created = new_child;
    new_child->setText(0,"Untitled Playlist");
    new_child->setFlags(new_child->flags() | Qt::ItemIsEditable);
    topLevelItem(1)->insertChild(0,new_child);
    editItem(new_child);
}

void MyTreeWidget::renameChild(QString new_name, QString child_name)
{
    for ( int a = 0; a < topLevelItem(1)->childCount(); a++ )
    {
        if ( topLevelItem(1)->child(a)->text(0) == child_name )
        {
            topLevelItem(1)->child(a)->setText(0,new_name);
            emit clickedToRenameChild(new_name,child_name);
            return;
        }
    }
}
void MyTreeWidget::rename()
{
    editItem(item_with_context_menu);
}
bool MyTreeWidget::hasConflict(QString name,int count_start)
{
    for ( int a = count_start; a < topLevelItem(1)->childCount(); a++ )
    {
        if ( topLevelItem(1)->child(a)->text(0) == name )
        {
            return true;
        }
    }
    return false;
}

void MyTreeWidget::overWriteChild(QString name)
{
    topLevelItem(1)->child(0)->setText(0,name);
    for ( int a = 1; a < topLevelItem(1)->childCount(); a++ )
    {
        if ( topLevelItem(1)->child(a)->text(0) == name )
        {
            QTreeWidgetItem* temp = topLevelItem(1)->child(a);
            delete temp;
            temp = Q_NULLPTR;
            return;
        }
    }
}




void MyTreeWidget::removeChild(QString name)
{
    for ( int a = 0; a < topLevelItem(1)->childCount(); a++ )
    {
        if ( topLevelItem(1)->child(a)->text(0) == name )
        {
            removeItemWidget(topLevelItem(1)->child(a),0);
            return;
        }
    }
}

void MyTreeWidget::contextMenu(QPoint p)
{
    if ( itemAt(p)->parent() == topLevelItem(1) )
    {
        item_with_context_menu = itemAt(p);
        context_menu->exec(mapToGlobal(p));
    }
}

void MyTreeWidget::open()
{
    emit clickedToOpen(item_with_context_menu->text(0));
}

void MyTreeWidget::play()
{
    emit clickedToSetCurrentPlaylist(item_with_context_menu->text(0));
    emit clickedToClearMap();
}



void MyTreeWidget::del()
{
    delete item_with_context_menu;
    item_with_context_menu = new QTreeWidgetItem;
    emit clickedToDelete(item_with_context_menu->text(0));
}

void MyTreeWidget::openFileLocation()
{
    emit clickedToOpenFileLocation(item_with_context_menu->text(0));
}



void MyTreeWidget::sendChildName(QTreeWidgetItem* new_child, int column)
{
    if ( last_item_created == new_child )
    {
        if ( hasConflict(new_child->text(column),1) )
        {
            QSignalBlocker blocker(this);
            QString name = new_child->text(column);
            new_child->setText(column,"");
            if ( QMessageBox::question(this,"test","A playlist named "+ name +".ext already exists. Do you want to overwrite it?",QMessageBox::StandardButton::Ok,QMessageBox::StandardButton::Cancel) == QMessageBox::StandardButton::Ok )
            {
                overWriteChild(name);
                blocker.unblock();
                emit overWritten(name);
                blocker.reblock();
            }
            else
            {
                delete new_child;
                new_child = Q_NULLPTR;
            }
            blocker.unblock();
        }
        else
            emit newChildCreated(new_child->text(column));
    }
}

