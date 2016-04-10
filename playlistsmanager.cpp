#include "playlistsmanager.h"



PlaylistsManager::PlaylistsManager(QVector<MyMusicPlayer*> playlist,QString name)
{
    setPlaylist(playlist);
    setName(name);
    setFilePath(name);
}

PlaylistsManager::PlaylistsManager(QString name)
{
    setName(name);
    setFilePath(name);
}

const QString& PlaylistsManager::getName()
{
    return name;
}

QVector<MyMusicPlayer*>& PlaylistsManager::getPlaylist()
{
    return playlist;
}

void PlaylistsManager::setName(QString name)
{
    this->name = name;
}

void PlaylistsManager::setFilePath(QString name)
{
    this->file_path = "c:/users/lorencepc/desktop/"+name+".txt";
}

const QString &PlaylistsManager::getAbsPath()
{
    return abs_path;
}




const QString& PlaylistsManager::getFilePath()
{
    return file_path;
}


void PlaylistsManager::setPlaylist(QVector<MyMusicPlayer*> playlist)
{
    this->playlist = playlist;
}

PlaylistsManager::PlaylistsManager()
    : playlist(), name()
{

}

PlaylistsManager::~PlaylistsManager()
{
    playlist.clear();
}







