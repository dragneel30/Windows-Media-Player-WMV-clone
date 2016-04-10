#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H

#include <QTreeWidget>

#include <QLineEdit>
#include <QSignalBlocker>
#include <QDebug>
#include <QMouseEvent>
#include <QMenu>
class MyTreeWidget : public QTreeWidget
{
    Q_OBJECT
public:
    MyTreeWidget(QWidget* parent = 0);
    ~MyTreeWidget();
    void mouseDoubleClickEvent(QMouseEvent*);
    void mousePressEvent(QMouseEvent*);
public slots:
    void addChild(QString=""); // child created externally
    void createChild(); // child create internally
    void renameChild(QString,QString);
    bool hasConflict(QString,int count_start = 0);
    void overWriteChild(QString);


    void removeChild(QString);
private slots:
    void contextMenu(QPoint);

    void open();
    void play();
    void rename();
    void del();
    void openFileLocation();

signals:
    void newChildCreated(QString);
    void clickedToSetCurrentPlaylist(QString);
    void clickedToMap(QString);
    void clickedToClearMap();
    void overWritten(QString);
    void clickedToRenameChild(QString,QString);


    void clickedToOpen(QString);
    void clickedToPlay();
    void clickedToRename();
    void clickedToDelete(QString);
    void clickedToOpenFileLocation(QString);

private:
    const QTreeWidgetItem* last_item_created = new QTreeWidgetItem; // for playlist
    QMenu* context_menu;
    QTreeWidgetItem* item_with_context_menu = new QTreeWidgetItem;
private slots:
    void sendChildName(QTreeWidgetItem*,int);

};


#endif // MYTREEWIDGET_H
