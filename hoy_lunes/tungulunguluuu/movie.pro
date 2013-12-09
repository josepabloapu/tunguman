HEADERS     = movieplayer.h \
              imageviewer.h \
              interfaces.h \
              paintarea.h \
              mainwindow.h
SOURCES     = main.cpp \
              paintarea.cpp \
              imageviewer.cpp \
              movieplayer.cpp \
              mainwindow.cpp

FORMS    += mainwindow.ui

TEMPLATE = app



# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/movie
sources.files = $$SOURCES $$HEADERS $$RESOURCES movie.pro animation.mng
sources.path = $$[QT_INSTALL_EXAMPLES]/widgets/movie
INSTALLS += target sources


symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)

wince*: {
   addFiles.files += *.mng
   addFiles.path = .
   DEPLOYMENT += addFiles
   DEPLOYMENT_PLUGIN += qmng qjpeg qgif
}

maemo5: include($$QT_SOURCE_TREE/examples/maemo5pkgrules.pri)

symbian: warning(This example might not fully work on Symbian platform)
maemo5: warning(This example might not fully work on Maemo platform)
simulator: warning(This example might not fully work on Simulator platform)
