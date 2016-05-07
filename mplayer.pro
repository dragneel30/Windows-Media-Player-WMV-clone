

QT       += core gui
QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mplayer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mylistwidget.cpp \
    mymusicplayer.cpp \
    mypushbutton.cpp \
    myslider.cpp \
    mylineedit.cpp \
    playlistsmanager.cpp \
    mytreewidget.cpp \
    mytablewidget.cpp \
    mymessagebox.cpp

HEADERS  += mainwindow.h \
    mylistwidget.h \
    mymusicplayer.h \
    mypushbutton.h \
    myslider.h \
    mylineedit.h \
    playlistsmanager.h \
    mytreewidget.h \
    mytablewidget.h \
    mymessagebox.h

FORMS    += mainwindow.ui

CONFIG += c++11
