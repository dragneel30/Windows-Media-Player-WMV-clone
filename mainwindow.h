#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlaylist>
#include "mymusicplayer.h"
#include <QListWidgetItem>
#include <QVector>
#include "playlistsmanager.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void removeSongFromCurrentPlaylist(QStringList);
    void addSongToCurrentPlaylist(QString);
    void browseSong(); //helper function

    // enabling and disabling of clickable widgets
    void offButton();
    void offButtonWhenStopped(bool);


    void renamePlaylist(QString,QString);
    void createNewPlaylist(QString); // helper function
    void changePlaylist(QString);
    void overWritePlaylist(QString);
    void mapPlaylistToTable(QString);
    void deletePlaylist(QString);

    void swapSong(int,int);
    void openFileLocation(QString);
    void openFileLocationPlaylist(QString);

private:
    Ui::MainWindow *ui;
    MyMusicPlayer song;
    QVector<MyMusicPlayer*>* current_playList;
    PlaylistsManager* playlist;


    QVector<PlaylistsManager*> playlists;


    const std::string txt_path = "c:/users/lorencepc/desktop/";
    void savePlaylistAsTxt(std::string);
};



#endif // MAINWINDOW_H
