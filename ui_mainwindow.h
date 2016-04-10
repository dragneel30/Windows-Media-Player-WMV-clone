/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mylineedit.h>
#include <mylistwidget.h>
#include <mypushbutton.h>
#include <myslider.h>
#include <mytablewidget.h>
#include <mytreewidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionOpenURL;
    QAction *actionSave_as;
    QAction *actionClose;
    QAction *actionCreatePlaylist;
    QAction *actionCreateAutoPlaylist;
    QAction *actionSaveNowPlayinglist;
    QAction *actionSaveNowPlayinglistAs;
    QAction *actionProperties;
    QAction *actionWorkoffline;
    QAction *actionExit;
    QAction *actionMusic;
    QAction *actionVideo;
    QAction *actionPictures;
    QAction *actionRecordedTV;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    MySlider *duration;
    QHBoxLayout *horizontalLayout;
    MyPushButton *shuffleButton;
    MyPushButton *repeatButton;
    QPushButton *stopButton;
    QPushButton *previousButton;
    MyPushButton *pauseButton;
    QPushButton *nextButton;
    MyPushButton *muteButton;
    QSlider *volume;
    MyTreeWidget *tree;
    QTabWidget *tabWidget;
    QWidget *playTab;
    MyListWidget *songList;
    MyLineEdit *currentPlaylistName;
    QWidget *burnTab;
    MyPushButton *sortButton;
    QWidget *syncTab;
    MyTableWidget *playlistTable;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuManage_librarier;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(673, 597);
        MainWindow->setMinimumSize(QSize(673, 0));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionOpenURL = new QAction(MainWindow);
        actionOpenURL->setObjectName(QStringLiteral("actionOpenURL"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionCreatePlaylist = new QAction(MainWindow);
        actionCreatePlaylist->setObjectName(QStringLiteral("actionCreatePlaylist"));
        actionCreateAutoPlaylist = new QAction(MainWindow);
        actionCreateAutoPlaylist->setObjectName(QStringLiteral("actionCreateAutoPlaylist"));
        actionSaveNowPlayinglist = new QAction(MainWindow);
        actionSaveNowPlayinglist->setObjectName(QStringLiteral("actionSaveNowPlayinglist"));
        actionSaveNowPlayinglistAs = new QAction(MainWindow);
        actionSaveNowPlayinglistAs->setObjectName(QStringLiteral("actionSaveNowPlayinglistAs"));
        actionProperties = new QAction(MainWindow);
        actionProperties->setObjectName(QStringLiteral("actionProperties"));
        actionWorkoffline = new QAction(MainWindow);
        actionWorkoffline->setObjectName(QStringLiteral("actionWorkoffline"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionMusic = new QAction(MainWindow);
        actionMusic->setObjectName(QStringLiteral("actionMusic"));
        actionVideo = new QAction(MainWindow);
        actionVideo->setObjectName(QStringLiteral("actionVideo"));
        actionPictures = new QAction(MainWindow);
        actionPictures->setObjectName(QStringLiteral("actionPictures"));
        actionRecordedTV = new QAction(MainWindow);
        actionRecordedTV->setObjectName(QStringLiteral("actionRecordedTV"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 490, 671, 55));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        duration = new MySlider(layoutWidget);
        duration->setObjectName(QStringLiteral("duration"));
        duration->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(duration);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        shuffleButton = new MyPushButton(layoutWidget);
        shuffleButton->setObjectName(QStringLiteral("shuffleButton"));

        horizontalLayout->addWidget(shuffleButton);

        repeatButton = new MyPushButton(layoutWidget);
        repeatButton->setObjectName(QStringLiteral("repeatButton"));

        horizontalLayout->addWidget(repeatButton);

        stopButton = new QPushButton(layoutWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        horizontalLayout->addWidget(stopButton);

        previousButton = new QPushButton(layoutWidget);
        previousButton->setObjectName(QStringLiteral("previousButton"));
        previousButton->setMaximumSize(QSize(24, 24));

        horizontalLayout->addWidget(previousButton);

        pauseButton = new MyPushButton(layoutWidget);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        horizontalLayout->addWidget(pauseButton);

        nextButton = new QPushButton(layoutWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setMaximumSize(QSize(24, 24));

        horizontalLayout->addWidget(nextButton);

        muteButton = new MyPushButton(layoutWidget);
        muteButton->setObjectName(QStringLiteral("muteButton"));

        horizontalLayout->addWidget(muteButton);

        volume = new QSlider(layoutWidget);
        volume->setObjectName(QStringLiteral("volume"));
        volume->setMaximumSize(QSize(100, 16777215));
        volume->setValue(50);
        volume->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(volume);


        verticalLayout->addLayout(horizontalLayout);

        tree = new MyTreeWidget(centralWidget);
        new QTreeWidgetItem(tree);
        new QTreeWidgetItem(tree);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(tree);
        __qtreewidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsTristate);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(tree);
        new QTreeWidgetItem(tree);
        new QTreeWidgetItem(tree);
        new QTreeWidgetItem(tree);
        new QTreeWidgetItem(tree);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(tree);
        __qtreewidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable);
        tree->setObjectName(QStringLiteral("tree"));
        tree->setGeometry(QRect(0, 0, 671, 491));
        tree->setAutoExpandDelay(-1);
        tree->setHeaderHidden(true);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(390, 0, 281, 492));
        playTab = new QWidget();
        playTab->setObjectName(QStringLiteral("playTab"));
        songList = new MyListWidget(playTab);
        songList->setObjectName(QStringLiteral("songList"));
        songList->setGeometry(QRect(0, 166, 275, 301));
        currentPlaylistName = new MyLineEdit(playTab);
        currentPlaylistName->setObjectName(QStringLiteral("currentPlaylistName"));
        currentPlaylistName->setGeometry(QRect(30, 146, 211, 20));
        currentPlaylistName->setFrame(false);
        tabWidget->addTab(playTab, QString());
        currentPlaylistName->raise();
        songList->raise();
        burnTab = new QWidget();
        burnTab->setObjectName(QStringLiteral("burnTab"));
        sortButton = new MyPushButton(burnTab);
        sortButton->setObjectName(QStringLiteral("sortButton"));
        sortButton->setGeometry(QRect(40, 190, 75, 23));
        tabWidget->addTab(burnTab, QString());
        syncTab = new QWidget();
        syncTab->setObjectName(QStringLiteral("syncTab"));
        tabWidget->addTab(syncTab, QString());
        playlistTable = new MyTableWidget(centralWidget);
        if (playlistTable->columnCount() < 12)
            playlistTable->setColumnCount(12);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        playlistTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        playlistTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        playlistTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        playlistTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        playlistTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        playlistTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        playlistTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        playlistTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        playlistTable->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        playlistTable->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        playlistTable->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        playlistTable->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        playlistTable->setObjectName(QStringLiteral("playlistTable"));
        playlistTable->setGeometry(QRect(160, 0, 511, 491));
        playlistTable->setDragEnabled(false);
        playlistTable->setDragDropOverwriteMode(true);
        playlistTable->setDragDropMode(QAbstractItemView::DragDrop);
        playlistTable->setDefaultDropAction(Qt::IgnoreAction);
        playlistTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        playlistTable->setSortingEnabled(true);
        playlistTable->setWordWrap(true);
        playlistTable->horizontalHeader()->setMinimumSectionSize(12);
        playlistTable->verticalHeader()->setVisible(false);
        playlistTable->verticalHeader()->setDefaultSectionSize(16);
        playlistTable->verticalHeader()->setMinimumSectionSize(16);
        MainWindow->setCentralWidget(centralWidget);
        tree->raise();
        layoutWidget->raise();
        playlistTable->raise();
        tabWidget->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 673, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuManage_librarier = new QMenu(menuFile);
        menuManage_librarier->setObjectName(QStringLiteral("menuManage_librarier"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpenURL);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionCreatePlaylist);
        menuFile->addAction(actionCreateAutoPlaylist);
        menuFile->addAction(actionSaveNowPlayinglist);
        menuFile->addAction(actionSaveNowPlayinglistAs);
        menuFile->addSeparator();
        menuFile->addAction(menuManage_librarier->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionProperties);
        menuFile->addAction(actionWorkoffline);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuManage_librarier->addAction(actionMusic);
        menuManage_librarier->addAction(actionVideo);
        menuManage_librarier->addAction(actionPictures);
        menuManage_librarier->addAction(actionRecordedTV);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open...                                     Ctrl + O", 0));
        actionOpenURL->setText(QApplication::translate("MainWindow", "Open URL...                             Ctrl + U", 0));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as...", 0));
        actionClose->setText(QApplication::translate("MainWindow", "Close                                        Ctrl + W", 0));
        actionCreatePlaylist->setText(QApplication::translate("MainWindow", "Create playlist                         Ctrl + N", 0));
        actionCreateAutoPlaylist->setText(QApplication::translate("MainWindow", "Create auto playlist", 0));
        actionSaveNowPlayinglist->setText(QApplication::translate("MainWindow", "Save Now Playing list", 0));
        actionSaveNowPlayinglistAs->setText(QApplication::translate("MainWindow", "Save Now Playing list as...", 0));
        actionProperties->setText(QApplication::translate("MainWindow", "Properties", 0));
        actionWorkoffline->setText(QApplication::translate("MainWindow", "Workoffline", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionMusic->setText(QApplication::translate("MainWindow", "Music", 0));
        actionVideo->setText(QApplication::translate("MainWindow", "Video", 0));
        actionPictures->setText(QApplication::translate("MainWindow", "Pictures", 0));
        actionRecordedTV->setText(QApplication::translate("MainWindow", "Recorded TV", 0));
        shuffleButton->setText(QApplication::translate("MainWindow", "Shuffled Off", 0));
        repeatButton->setText(QApplication::translate("MainWindow", "Repeat Off", 0));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", 0));
        previousButton->setText(QApplication::translate("MainWindow", "<<", 0));
        pauseButton->setText(QApplication::translate("MainWindow", "Play", 0));
        nextButton->setText(QApplication::translate("MainWindow", ">>", 0));
        muteButton->setText(QApplication::translate("MainWindow", "Unmuted", 0));
        QTreeWidgetItem *___qtreewidgetitem = tree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "1", 0));

        const bool __sortingEnabled = tree->isSortingEnabled();
        tree->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = tree->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("MainWindow", "Library", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = tree->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("MainWindow", "Playlist", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = tree->topLevelItem(2);
        ___qtreewidgetitem3->setText(0, QApplication::translate("MainWindow", "Music", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem3->child(0);
        ___qtreewidgetitem4->setText(0, QApplication::translate("MainWindow", "Artist", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem3->child(1);
        ___qtreewidgetitem5->setText(0, QApplication::translate("MainWindow", "Album", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem3->child(2);
        ___qtreewidgetitem6->setText(0, QApplication::translate("MainWindow", "Genre", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = tree->topLevelItem(3);
        ___qtreewidgetitem7->setText(0, QApplication::translate("MainWindow", "Videos", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = tree->topLevelItem(4);
        ___qtreewidgetitem8->setText(0, QApplication::translate("MainWindow", "Pictures", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = tree->topLevelItem(5);
        ___qtreewidgetitem9->setText(0, QApplication::translate("MainWindow", "Recorded TV", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = tree->topLevelItem(6);
        ___qtreewidgetitem10->setText(0, QApplication::translate("MainWindow", "Other media", 0));
        QTreeWidgetItem *___qtreewidgetitem11 = tree->topLevelItem(8);
        ___qtreewidgetitem11->setText(0, QApplication::translate("MainWindow", "Other Libraries", 0));
        tree->setSortingEnabled(__sortingEnabled);

        currentPlaylistName->setText(QApplication::translate("MainWindow", "                       Unsaved list                          ", 0));
        tabWidget->setTabText(tabWidget->indexOf(playTab), QApplication::translate("MainWindow", "Play", 0));
        sortButton->setText(QApplication::translate("MainWindow", "sort button", 0));
        tabWidget->setTabText(tabWidget->indexOf(burnTab), QApplication::translate("MainWindow", "Burn", 0));
        tabWidget->setTabText(tabWidget->indexOf(syncTab), QApplication::translate("MainWindow", "Sync", 0));
        QTableWidgetItem *___qtablewidgetitem = playlistTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "#", 0));
        QTableWidgetItem *___qtablewidgetitem1 = playlistTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Title", 0));
        QTableWidgetItem *___qtablewidgetitem2 = playlistTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Length", 0));
        QTableWidgetItem *___qtablewidgetitem3 = playlistTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Rating", 0));
        QTableWidgetItem *___qtablewidgetitem4 = playlistTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Contributing artist", 0));
        QTableWidgetItem *___qtablewidgetitem5 = playlistTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Album", 0));
        QTableWidgetItem *___qtablewidgetitem6 = playlistTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Genre", 0));
        QTableWidgetItem *___qtablewidgetitem7 = playlistTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Release year", 0));
        QTableWidgetItem *___qtablewidgetitem8 = playlistTable->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Composer", 0));
        QTableWidgetItem *___qtablewidgetitem9 = playlistTable->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Size", 0));
        QTableWidgetItem *___qtablewidgetitem10 = playlistTable->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "New Column", 0));
        QTableWidgetItem *___qtablewidgetitem11 = playlistTable->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Album artist", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuManage_librarier->setTitle(QApplication::translate("MainWindow", "Manage libraries", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
