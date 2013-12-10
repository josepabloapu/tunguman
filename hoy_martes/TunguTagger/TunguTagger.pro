#-------------------------------------------------
#
# Project created by QtCreator 2013-12-08T23:56:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TunguTagger
TEMPLATE = app

# Tell qmake to use pkg-config to find QtGStreamer.
CONFIG += link_pkgconfig

# Now tell qmake to link to QtGStreamer and also use its include path and Cflags.
contains(QT_VERSION, ^4\\..*) {
  PKGCONFIG += QtGStreamer-0.10 QtGStreamerUi-0.10
}

SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    mediaapp.cpp \
    imageviewer.cpp \
    paintarea.cpp

HEADERS  += mainwindow.h \
    player.h \
    mediaapp.h \
    imageviewer.h \
    paintarea.h \
    interfaces.h

FORMS    += mainwindow.ui
