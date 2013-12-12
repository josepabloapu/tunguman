#-------------------------------------------------
#
# Project created by QtCreator 2013-12-11T00:02:42
#
#-------------------------------------------------

QT       += core gui phonon
QT       += sql
QT       += webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TunguApp
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        videoplayer.cpp \
    mainwindow.cpp

HEADERS  += videoplayer.h \
    mainwindow.h

FORMS += \
    mainwindow.ui
