#include "mediaapp.h"
#include <QApplication>
#include <QtGStreamer/QGst/Init>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGst::init(&argc, &argv);

    MediaApp media;
    media.show();

    if (argc == 2) {
        media.openFile(argv[1]);
    }

    return app.exec();
}
