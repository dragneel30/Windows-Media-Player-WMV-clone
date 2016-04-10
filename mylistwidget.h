#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QListWidget>

#include <QMediaPlayer>
#include <QEvent>
#include <QList>

#include <QMenu>
class MyListWidget : public QListWidget
{
    Q_OBJECT
public:
    MyListWidget(QWidget* parent = 0);
    ~MyListWidget();
    void mouseDoubleClickEvent(QMouseEvent*);
    void keyPressEvent(QKeyEvent*);
    bool isSongNameExist(QString);
    bool addSongName(QString);
    void setList(QStringList);
signals:
    void clickedToPlay(QString);

    void playedToConfig(bool);

    void clickedToRemove(QStringList);

    void clickedToSwap(int,int);
    void clickedToOpenFileLocation(QString);
public slots:
    void sortSongName();
    void nextSongName();
    void previousSongName();
    void setShuffledSongName(bool);
    void setWillRepeatToTheTop(bool);
    void emitClickedToPlay();

    //context menu
    void play();
    void removeFromPlaylist();
    void moveUp();
    void moveDown();
    void properties();
    void openFileLocation();

private slots:
    void contextMenu(QPoint);
private:
    qint32 active_item;
    bool isShuffled;
    QString current_playlist_name;
    void nextActiveItem(int);
    void removeSongName();
    bool willRepeatToTheTop;
    QMenu* context_menu;
    const QListWidgetItem* item_with_context_activated = new QListWidgetItem;
};




#endif // MYLISTWIDGET_H
