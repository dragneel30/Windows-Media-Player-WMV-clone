#include "mylistwidget.h"
#include <QMouseEvent>
#include <QStringList>
#include <cstdlib>
#include <ctime>
#include <QFileInfo>
#include <QDesktopServices>
MyListWidget::MyListWidget(QWidget* parent)
    :QListWidget(parent), active_item(0), isShuffled(false), willRepeatToTheTop(true), context_menu(new QMenu)
{


    setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(contextMenu(QPoint)));

    srand(time(NULL));
    context_menu->addAction("play",this,SLOT(play()));
    context_menu->addAction("add to");
    context_menu->addSeparator();
    context_menu->addAction("rate");
    context_menu->addSeparator();
    context_menu->addAction("remove from playlist",this,SLOT(removeFromPlaylist()));
    context_menu->addAction("move up",this,SLOT(moveUp()));
    context_menu->addAction("move down",this,SLOT(moveDown()));
    context_menu->addSeparator();
    context_menu->addAction("properties",this,SLOT(properties()));
    context_menu->addSeparator();
    context_menu->addAction("open file location",this,SLOT(openFileLocation()));
}

MyListWidget::~MyListWidget()
{

}



void MyListWidget::mouseDoubleClickEvent(QMouseEvent* e)
{
    if ( e->button() == Qt::LeftButton )
    {
        if ( currentRow() >= 0 && currentRow() < count() && active_item != currentRow() )
        {
            active_item = currentRow();
            emit clickedToPlay(currentItem()->text());
            emit playedToConfig(true);
        }
    }
}


void MyListWidget::keyPressEvent(QKeyEvent *event)
{
    if ( event->key() == Qt::Key_Delete )
    {
        if ( !selectedItems().empty() )
            removeSongName();
    }
}


bool MyListWidget::isSongNameExist(QString song_name)
{
    return ( findItems(song_name,Qt::MatchExactly).empty() );
}

bool MyListWidget::addSongName(QString song_path)
{
    QString song_name = QFileInfo(song_path).baseName();
    if ( findItems(song_name,Qt::MatchExactly).empty() )
    {
        addItem(song_name);
        return true;
    }
    return false;
}

void MyListWidget::setList(QStringList new_list)
{
    clear();
    if ( !new_list.isEmpty() )
    {
        addItems(new_list);
        active_item = 0;
        emitClickedToPlay();
        emit playedToConfig(true);
    }
}

void MyListWidget::emitClickedToPlay()
{
    emit clickedToPlay(item(active_item)->text());
}

void MyListWidget::play()
{
    emit clickedToPlay(item_with_context_activated->text());
}

void MyListWidget::removeFromPlaylist()
{
    emit clickedToRemove(QStringList(item_with_context_activated->text()));
    delete item_with_context_activated;
    item_with_context_activated = new QListWidgetItem;
}

void MyListWidget::moveUp()
{
    int first = row(item_with_context_activated);
    int second = row(item_with_context_activated) - 1;
    emit clickedToSwap(first,second);
    std::swap(*item(first),*item(second));
}

void MyListWidget::moveDown()
{
    int first = row(item_with_context_activated);
    int second = row(item_with_context_activated) + 1;
    emit clickedToSwap(first,second);
    std::swap(*item(first),*item(second));
}

void MyListWidget::properties()
{

}

void MyListWidget::openFileLocation()
{
    emit clickedToOpenFileLocation(item_with_context_activated->text());
}

void MyListWidget::contextMenu(QPoint p)
{
    QListWidgetItem* temp = itemAt(p);
    if ( temp != Q_NULLPTR )
    {
        if ( temp == item(0) )
            context_menu->actions()[6]->setEnabled(false);
        else
            context_menu->actions()[6]->setEnabled(true);
        if ( temp == item(count()-1) )
            context_menu->actions()[7]->setEnabled(false);
        else
            context_menu->actions()[7]->setEnabled(true);

        item_with_context_activated = temp;
        context_menu->exec(mapToGlobal(p));
    }
}

void MyListWidget::nextActiveItem(int p)
{
    if ( isShuffled )
    {
        int previous_active_item = active_item;
        while( active_item == previous_active_item )
        active_item = rand() % count() + 0;
    }
    else
    {
        active_item += p;
        if ( active_item < 0 )
        {
            active_item = count() - 1;
        }
        else if ( active_item >= count() )
        {
            active_item = 0;
            if ( !willRepeatToTheTop )
                return;
        }
    }
    emitClickedToPlay();
    emit playedToConfig(true);
}

void MyListWidget::removeSongName()
{
        QStringList deletedItems;
        QList<QListWidgetItem*> sItems = selectedItems();
        for ( QList<QListWidgetItem*>::iterator iter = sItems.begin(); iter != sItems.end(); iter++ )
        {
            deletedItems << (*iter)->text();
        }
        emit clickedToRemove(deletedItems);
        for ( qint32 a = 0; a < selectedItems().size(); a++ )
        {
            delete selectedItems()[a];
        }
}
void MyListWidget::setWillRepeatToTheTop(bool will)
{
    willRepeatToTheTop = will;
}


void MyListWidget::nextSongName()
{
    nextActiveItem(1);
}

void MyListWidget::previousSongName()
{
    nextActiveItem(-1);
}

void MyListWidget::setShuffledSongName(bool p)
{
    isShuffled = p;
}

void MyListWidget::sortSongName()
{
    QString s_active_item = item(active_item)->text();
    sortItems(Qt::AscendingOrder);
    QListWidgetItem* ptr_active_item = findItems(s_active_item,Qt::MatchExactly).front();
    active_item = row(ptr_active_item);
}


