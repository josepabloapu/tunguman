#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QWidget>
#include <phonon/MediaObject>
#include <phonon/VideoWidget>
#include <phonon/AudioOutput>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QCursor;
class QPixmap;
class QGridLayout;
class QHBoxLayout;
class QLabel;
class QMovie;
class QSlider;
class QSpinBox;
class QToolButton;
class QVBoxLayout;
QT_END_NAMESPACE

class VideoPlayer : public QWidget
{
    Q_OBJECT

public:
    VideoPlayer(QWidget *parent = 0);
    ~VideoPlayer();
    void openFile(const QString &fileName);

private slots:
    void open();



private:
    void createButtons();
    QString currentMovieDirectory;
    Phonon::MediaObject *movie;
    Phonon::VideoWidget *video;
    Phonon::AudioOutput *audio;
    QToolButton *openButton;
    QToolButton *playButton;
    QToolButton *pauseButton;
    QToolButton *stopButton;
    QToolButton *quitButton;

    QGridLayout *controlsLayout;
    QHBoxLayout *buttonsLayout;
    QVBoxLayout *mainLayout;
};

#endif // VIDEOPLAYER_H
