#include "mymusicplayer.h"
#include <QFileInfo>



MyMusicPlayer::MyMusicPlayer()
    :audio(new QMediaPlayer)
{}

MyMusicPlayer::MyMusicPlayer(QString name)
    :audio(new QMediaPlayer),name()
{
    audio->setMedia(QUrl(name));
    this->name = QFileInfo(name).baseName();
    audio->setNotifyInterval(16);
    qDebug() << this->name;
}

MyMusicPlayer::~MyMusicPlayer()
{
    delete audio;
    audio = Q_NULLPTR;
}

const QString& MyMusicPlayer::getName() const
{
    return name;
}

qint32 MyMusicPlayer::durationToMinute(qint64 duration)
{
    return duration/1000;
}


void MyMusicPlayer::play(QString song_name)
{
    if ( song_name == name )
    {
        emit durationRequested(0,audio->duration());
        emit played(true);
        audio->play();
    }
}

void MyMusicPlayer::pause()
{
    if ( audio->state() == QMediaPlayer::State::PlayingState )
        audio->pause();
}

void MyMusicPlayer::stop()
{
    if ( audio->state() == QMediaPlayer::State::PlayingState || audio->state() == QMediaPlayer::State::PausedState )
        audio->stop();
}

void MyMusicPlayer::resume()
{
    if ( audio->state() == QMediaPlayer::State::PausedState )
        audio->play();
}

void MyMusicPlayer::skipPosition(int position)
{
    if ( audio->state() == QMediaPlayer::State::PlayingState )
        audio->setPosition(position);
}

QMediaPlayer *MyMusicPlayer::getAudio() const
{
    return audio;
}


