#include "videoplayer.h"

#include <QFileDialog>
#include <QString>
#include <QtGui>

VideoPlayer::VideoPlayer(QWidget *parent) : QWidget(parent)
{
    Phonon::MediaObject *movie = new Phonon::MediaObject(this);
    Phonon::VideoWidget *video = new Phonon::VideoWidget(this);
    video->setAspectRatio(Phonon::VideoWidget::AspectRatioAuto);
    video->setScaleMode(Phonon::VideoWidget::ScaleAndCrop);
    video->setGeometry(0,0,600,400);
    Phonon::AudioOutput *audio = new Phonon::AudioOutput(Phonon::VideoCategory,this);
    movie->clearQueue();
    Phonon::createPath(movie, video); // to link the mediaobject with the video widget.
    Phonon::createPath(movie, audio);

    createButtons();

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(video);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);

    QString fileName = QFileDialog::getOpenFileName(this, tr("open a file"));
    movie->enqueue(Phonon::MediaSource(fileName));
    movie->play();
}

VideoPlayer::~VideoPlayer()
{

}

void VideoPlayer::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open a file"), currentMovieDirectory);
    if (!fileName.isEmpty())
        openFile(fileName);
}

void VideoPlayer::openFile(const QString &fileName)
{
    currentMovieDirectory = QFileInfo(fileName).path();
    movie->stop();
    movie->enqueue(Phonon::MediaSource(fileName));
}

void VideoPlayer::createButtons()
{
    QSize iconSize(36, 36);

    openButton = new QToolButton;
    openButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
    openButton->setIconSize(iconSize);
    openButton->setToolTip(tr("Open File"));
    connect(openButton, SIGNAL(clicked()), this, SLOT(open()));

    playButton = new QToolButton;
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    playButton->setIconSize(iconSize);
    playButton->setToolTip(tr("Play"));
    connect(playButton, SIGNAL(clicked()), this, SLOT(play()));

    pauseButton = new QToolButton;
    pauseButton->setCheckable(true);
    pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    pauseButton->setIconSize(iconSize);
    pauseButton->setToolTip(tr("Pause"));
    connect(pauseButton, SIGNAL(clicked(bool)), this, SLOT(pause()));

    stopButton = new QToolButton;
    stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    stopButton->setIconSize(iconSize);
    stopButton->setToolTip(tr("Stop"));
    connect(stopButton, SIGNAL(clicked()), this, SLOT(stop()));

    quitButton = new QToolButton;
    quitButton->setIcon(style()->standardIcon(QStyle::SP_DialogCloseButton));
    quitButton->setIconSize(iconSize);
    quitButton->setToolTip(tr("Quit"));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(openButton);
    buttonsLayout->addWidget(playButton);
    buttonsLayout->addWidget(pauseButton);
    buttonsLayout->addWidget(stopButton);
    buttonsLayout->addWidget(quitButton);
    buttonsLayout->addStretch();
}


//hay que crear estas funciones
void VideoPlayer::stop () {}
void VideoPlayer::play () {}
void VideoPlayer::pause () {}
