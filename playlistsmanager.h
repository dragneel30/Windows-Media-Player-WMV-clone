#ifndef PLAYLISTSMANAGER_H
#define PLAYLISTSMANAGER_H

#include "mymusicplayer.h"
#include <QVector>

class PlaylistsManager : public QObject
{
    Q_OBJECT
public:
    PlaylistsManager(QVector<MyMusicPlayer*>,QString);
    PlaylistsManager(QString name);
    PlaylistsManager();
    ~PlaylistsManager();
    const QString& getName();
    QVector<MyMusicPlayer*>& getPlaylist();
    void setPlaylist(QVector<MyMusicPlayer*> playlist);
    void setName(QString name);
    const QString& getFilePath();
    void setFilePath(QString);
    const QString& getAbsPath();

private:
    QVector<MyMusicPlayer*> playlist;
    QString name;
    QString file_path;
    const QString abs_path = "c:/users/lorencepc/desktop/";
};

#endif // PLAYLISTSMANAGER_H
