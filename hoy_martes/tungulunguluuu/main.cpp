
#include <QApplication>

#include "movieplayer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MoviePlayer player;

    player.show();

#if defined(Q_OS_SYMBIAN)

    player.showMaximized();

#else

    player.show();

#endif

    return app.exec();
}
