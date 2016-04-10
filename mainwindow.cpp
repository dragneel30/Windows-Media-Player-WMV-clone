#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTime>
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QDesktopServices>
#include <fstream>
#include <cstdlib>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),song(),current_playList(new QVector<MyMusicPlayer*>),playlist(new PlaylistsManager),playlists()
{
    ui->setupUi(this);


    offButton();


    connect(ui->tree,SIGNAL(clickedToClearMap()),ui->playlistTable,SLOT(clearContents()));
    connect(ui->tree,SIGNAL(clickedToMap(QString)),this,SLOT(mapPlaylistToTable(QString)));
    connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(browseSong()));
    connect(ui->songList,SIGNAL(clickedToRemove(QStringList)),this,SLOT(removeSongFromCurrentPlaylist(QStringList)));
    connect(ui->sortButton,SIGNAL(clicked(bool)),ui->songList,SLOT(sortSongName()));
    connect(ui->nextButton,SIGNAL(clicked(bool)),ui->songList,SLOT(nextSongName()));
    connect(ui->previousButton,SIGNAL(clicked(bool)),ui->songList,SLOT(previousSongName()));
    connect(ui->shuffleButton,SIGNAL(clickedToSetShuffled(bool)),ui->songList,SLOT(setShuffledSongName(bool)));
    connect(ui->duration,SIGNAL(trackFinished()),ui->songList,SLOT(nextSongName()));
    connect(ui->repeatButton,SIGNAL(clickedToSetRepeated(bool)),ui->songList,SLOT(setWillRepeatToTheTop(bool)));

    connect(ui->stopButton,SIGNAL(clicked(bool)),this,SLOT(offButtonWhenStopped(bool)));
    connect(ui->actionClose,SIGNAL(triggered(bool)),this,SLOT(offButtonWhenStopped(bool)));
    connect(ui->songList,SIGNAL(playedToConfig(bool)),this,SLOT(offButtonWhenStopped(bool)));
    connect(ui->songList,SIGNAL(clickedToOpenFileLocation(QString)),this,SLOT(openFileLocation(QString)));
    connect(ui->currentPlaylistName,SIGNAL(editingFinishedEmitted(QString,QString)),this,SLOT(renamePlaylist(QString,QString)));

    connect(ui->tree,SIGNAL(clickedToSetCurrentPlaylist(QString)),this,SLOT(changePlaylist(QString)));

    connect(ui->pauseButton,SIGNAL(clickedToResume()),ui->songList,SLOT(emitClickedToPlay()));

    connect(ui->actionCreatePlaylist,SIGNAL(triggered(bool)),ui->tree,SLOT(createChild()));
    connect(ui->tree,SIGNAL(newChildCreated(QString)),this,SLOT(createNewPlaylist(QString)));
    connect(ui->songList,SIGNAL(clickedToSwap(int,int)),this,SLOT(swapSong(int,int)));
     ////****************************************////////////

    connect(ui->tree,SIGNAL(overWritten(QString)),this,SLOT(overWritePlaylist(QString)));
    connect(ui->tree,SIGNAL(clickedToOpen(QString)),this,SLOT(mapPlaylistToTable(QString)));
    connect(ui->tree,SIGNAL(clickedToOpenFileLocation(QString)),this,SLOT(openFileLocationPlaylist(QString)));
    connect(ui->tree,SIGNAL(clickedToDelete(QString)),this,SLOT(deletePlaylist(QString)));
    addSongToCurrentPlaylist("C:/Users/Lorencepc/Desktop/one call away.mp3");
    addSongToCurrentPlaylist("C:/Users/Lorencepc/Desktop/work from home.mp3");

}

MainWindow::~MainWindow()
{
    delete ui;
    ui = Q_NULLPTR;
}



void MainWindow::createNewPlaylist(QString playlist_name)
{
    PlaylistsManager* new_playlist = new PlaylistsManager(playlist_name);
    playlists.push_back(new_playlist);
    savePlaylistAsTxt(playlist_name.toStdString());
}

void MainWindow::changePlaylist(QString playlist_name)
{
    for ( QVector<PlaylistsManager*>::iterator iter = playlists.begin(); iter != playlists.end(); iter++ )
    {
        if ( (*iter)->getName() == playlist_name )
        {
            ui->stopButton->click();
            current_playList = &(*iter)->getPlaylist();
            playlist = &(*(*iter));
            QStringList new_list;
            for ( QVector<MyMusicPlayer*>::iterator names = current_playList->begin(); names != current_playList->end(); names++ )
            {
                new_list << (*names)->getName();
            }
            ui->songList->setList(new_list);
            ui->currentPlaylistName->setText(playlist_name);
        }
    }
}

void MainWindow::overWritePlaylist(QString name)
{
    for ( int a = 0; a < playlists.size(); a++ )
    {
        if ( playlists[a]->getName() == name )
        {
            playlists[a]->getPlaylist().clear();
            std::ofstream new_file((txt_path+name.toStdString()).c_str());
            return;
        }
    }
}

void MainWindow::mapPlaylistToTable(QString playlist_name)
{
    if ( playlist_name != playlist->getName() )
    {
        ui->playlistTable->setRowCount(1);
        for ( QVector<PlaylistsManager*>::iterator iter = playlists.begin(); iter != playlists.end(); iter++ )
        {
            if ( (*iter)->getName() == playlist_name )
            {
                for ( QVector<MyMusicPlayer*>::iterator iter2 = (*iter)->getPlaylist().begin(); iter2 != (*iter)->getPlaylist().end(); iter2++ )
                {
                    ui->playlistTable->fillContent((*iter2)->getName(),1);
                    ui->playlistTable->fillContent("",11);
                }
            }
        }
    }
}

void MainWindow::deletePlaylist(QString playlist_name)
{
    for ( QVector<PlaylistsManager*>::iterator iter = playlists.begin(); iter != playlists.end(); iter++ )
    {
        if ( (*iter)->getName() == playlist_name )
        {
            delete (*iter);
            *iter = Q_NULLPTR;
            remove((txt_path+playlist_name.toStdString()).c_str());
            return;
        }
    }
}

void MainWindow::swapSong(int first,int second)
{
    std::swap((*current_playList)[first],(*current_playList)[second]);
}

void MainWindow::openFileLocation(QString filename)
{
    for (QVector<MyMusicPlayer*>::iterator iter = current_playList->begin(); iter != current_playList->end(); iter++ )
    {
        if ( (*iter)->getName() == filename )
        {
            QDesktopServices::openUrl(QFileInfo((*iter)->getAudio()->media().canonicalUrl().toString()).absolutePath());

        }
    }
}

void MainWindow::openFileLocationPlaylist(QString filename)
{
    for (QVector<PlaylistsManager*>::iterator iter = playlists.begin(); iter != playlists.end(); iter++ )
    {
        if ( (*iter)->getName() == filename )
        {
            QDesktopServices::openUrl(QUrl((*iter)->getAbsPath()));
        }
    }
}

void MainWindow::savePlaylistAsTxt(std::string playlist_name)
{
    std::string absFile = txt_path + playlist_name + ".txt";
    std::ofstream new_playlist(absFile.c_str());
}

void MainWindow::renamePlaylist(QString new_name, QString current_name)
{
    std::string oldAbsFile = txt_path + current_name.toStdString() + ".txt";
    std::string newAbsFile = txt_path + new_name.toStdString() + ".txt";
    if ( ui->tree->hasConflict(current_name) )
    {
        if ( !ui->tree->hasConflict(new_name) )
        {
            ui->tree->renameChild(new_name,current_name);
            for ( int a = 0; a < playlists.size(); a++ )
            {
                if ( playlists[a]->getName() == current_name )
                {
                    playlists[a]->setName(new_name);
                    std::rename(oldAbsFile.c_str(),newAbsFile.c_str());
                    return;
                }
            }
        }
    }
    else
    {
            ui->tree->addChild(new_name);
            PlaylistsManager* new_playlist = new PlaylistsManager(*current_playList,new_name);
            playlists.push_back(new_playlist);
            savePlaylistAsTxt(newAbsFile);
            std::ofstream write(newAbsFile.c_str());
            for ( QVector<MyMusicPlayer*>::iterator iter = current_playList->begin(); iter != current_playList->end(); iter++ )
            {
                write << QFileInfo((*iter)->getAudio()->media().canonicalUrl().toString()).absoluteFilePath().toStdString() << std::endl;
            }
    }
}

void MainWindow::addSongToCurrentPlaylist(QString song_path)
{
    if ( !song_path.isEmpty() )
    {
        if ( ui->songList->addSongName(song_path) )
        {
            current_playList->push_back(new MyMusicPlayer(song_path));

            std::ofstream file(playlist->getFilePath().toStdString().c_str(),std::ios_base::app);
            file << song_path.toStdString();

            if ( ui->songList->count() == 1 ) // will not execute if count > 2 for less overhead
            {
                ui->pauseButton->setEnabled(true);
                ui->nextButton->setEnabled(true);
                ui->stopButton->setEnabled(true);
            }
            else if ( ui->songList->count() == 2 )
            {
                ui->previousButton->setEnabled(true);
            }
        }

        connect(current_playList->back(),SIGNAL(played(bool)),this,SLOT(offButtonWhenStopped(bool)));
        connect(ui->actionClose,SIGNAL(triggered(bool)),current_playList->back(),SLOT(stop()));
        connect(ui->stopButton,SIGNAL(clicked(bool)),current_playList->back(),SLOT(stop()));
        connect(ui->songList,SIGNAL(clickedToPlay(QString)),current_playList->back(),SLOT(stop())); //stop the current playing song if there is
        connect(ui->songList,SIGNAL(clickedToPlay(QString)),current_playList->back(),SLOT(play(QString))); //  play
        connect(ui->pauseButton,SIGNAL(clickedToPause()),current_playList->back(),SLOT(pause()));
        connect(ui->pauseButton,SIGNAL(clickedToResume()),current_playList->back(),SLOT(resume()));
        connect(ui->muteButton,SIGNAL(clickedToSetMuted(bool)),current_playList->back()->getAudio(),SLOT(setMuted(bool)));
        connect(ui->volume,SIGNAL(valueChanged(int)),current_playList->back()->getAudio(),SLOT(setVolume(int)));
        connect(current_playList->back(),SIGNAL(durationRequested(qint32,qint32)),ui->duration,SLOT(c_setRange(int,int)));


        connect(current_playList->back()->getAudio(),SIGNAL(positionChanged(qint64)),ui->duration,SLOT(movePosition(qint64)));


        connect(ui->duration,SIGNAL(positionSkipped(int)),current_playList->back(),SLOT(skipPosition(int)));
    }
}


void MainWindow::removeSongFromCurrentPlaylist(QStringList deletedItems)
{
    for  ( QStringList::iterator l_iter = deletedItems.begin(); l_iter != deletedItems.end(); l_iter++ )
    {
        qint32 a = 0;
        for ( QVector<MyMusicPlayer*>::iterator v_iter = current_playList->begin(); v_iter != current_playList->end(); v_iter++ )
        {
            if ( (*l_iter) == (*v_iter)->getName() )
            {
                std::ifstream read(playlist->getFilePath().toStdString().c_str());
                std::ofstream write((txt_path+"temp.txt").c_str());
                std::string temp = "";
                if ( getline(read,temp))
                {
                    if ( temp != (*l_iter).toStdString() )
                    {
                        write << temp << std::endl;
                    }
                }
                read.close();
                write.close();
                remove(playlist->getFilePath().toStdString().c_str());
                std::rename((txt_path+"temp.txt").c_str(),playlist->getFilePath().toStdString().c_str());
                delete *v_iter;
                *v_iter = Q_NULLPTR;
                current_playList->remove(a);

                break;
            }
            ++a;
        }
    }
    if ( ui->songList->count() == 1 ) // this function will delete >=1 song , if its one then 1>=1 == true
    {
        offButton();
    }
    else if ( ui->songList->count() == 2 )
    {
        ui->previousButton->setEnabled(false);
    }
}

void MainWindow::browseSong()
{
    addSongToCurrentPlaylist(QFileDialog::getOpenFileName(this,"Open File","","Media File(*.mp3)"));
}

void MainWindow::offButton()
{
    ui->nextButton->setEnabled(false);
    ui->previousButton->setEnabled(false);
    ui->pauseButton->setEnabled(false);
    ui->stopButton->setEnabled(false);
}

void MainWindow::offButtonWhenStopped(bool isEnabled)
{
    if ( !isEnabled )
        ui->pauseButton->setText("Play");
    else
        ui->pauseButton->setText("Pause");
    ui->stopButton->setEnabled(isEnabled);
    ui->actionClose->setEnabled(isEnabled);
}



