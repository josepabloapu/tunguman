#-------------------------------------------------
#
# Project created by QtCreator 2013-12-11T00:02:42
#
#-------------------------------------------------

QT       += core gui phonon sql webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TunguApp
TEMPLATE = app


SOURCES += main.cpp\
        videoplayer.cpp \
    mainwindow.cpp \
    secondwindow.cpp

HEADERS  += videoplayer.h \
    mainwindow.h \
    secondwindow.h

FORMS += \
    mainwindow.ui \
    secondwindow.ui
