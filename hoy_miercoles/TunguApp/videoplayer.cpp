#include "videoplayer.h"
#include "mainwindow.h"

#include <QFileDialog>
#include <QString>
#include <QtGui>
#include <QImage>

VideoPlayer::VideoPlayer(QWidget *parent) : QWidget(parent)
{
    movie = new Phonon::MediaObject(this);
    video = new Phonon::VideoWidget(this);
    audio = new Phonon::AudioOutput(Phonon::VideoCategory,this);

    video->setGeometry(0,0,600,400);

    Phonon::createPath(movie, video);
    Phonon::createPath(movie, audio);

    //createControls();
    createButtons();

    //connect(movie, SIGNAL(tick(int)), this, SLOT(updateSeekSlider()));
    //connect(movie, SIGNAL(stateChanged(QMovie::MovieState)),this, SLOT(updateButtons()));
    //connect(fitCheckBox, SIGNAL(clicked()), this, SLOT(fitToWindow()));
    //connect(frameSlider, SIGNAL(valueChanged(int)), this, SLOT(goToFrame(int)));
    //connect(speedSpinBox, SIGNAL(valueChanged(int)), movie, SLOT(setSpeed(int)));

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(video);
    mainLayout->addLayout(buttonsLayout);
    //mainLayout->addLayout(controlsLayout);
    setLayout(mainLayout);
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
    movie->enqueue(Phonon::MediaSource(fileName));
    video->setScaleMode(Phonon::VideoWidget::ScaleAndCrop);
}

void VideoPlayer::snapshot()
{

    MainWindow *mainWindow;
    mainWindow = new MainWindow();
    mainWindow->open(video->snapshot());
    mainWindow->show();
}

void VideoPlayer::createControls()
{
    seekSlider = new Phonon::SeekSlider(this);
    volumeSlider = new Phonon::VolumeSlider(this);
    controlsLayout = new QGridLayout;
    controlsLayout->addWidget(seekSlider, 1, 1, 1, 5);
    controlsLayout->addWidget(volumeSlider, 1, 6, 1, 2);
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
    connect(playButton, SIGNAL(clicked()), movie, SLOT(play()));

    pauseButton = new QToolButton;
    pauseButton->setCheckable(true);
    pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    pauseButton->setIconSize(iconSize);
    pauseButton->setToolTip(tr("Pause"));
    connect(pauseButton, SIGNAL(clicked(bool)), movie, SLOT(pause()));

    stopButton = new QToolButton;
    stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    stopButton->setIconSize(iconSize);
    stopButton->setToolTip(tr("Stop"));
    connect(stopButton, SIGNAL(clicked()), movie, SLOT(stop()));

    quitButton = new QToolButton;
    quitButton->setIcon(style()->standardIcon(QStyle::SP_DialogCloseButton));
    quitButton->setIconSize(iconSize);
    quitButton->setToolTip(tr("Quit"));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));

    captureButton = new QToolButton;
    captureButton->setIcon(style()->standardIcon(QStyle::SP_ArrowDown));
    captureButton->setIconSize(iconSize);
    captureButton->setToolTip(tr("Snapshot"));
    connect(captureButton, SIGNAL(clicked()), this, SLOT(snapshot()));

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(openButton);
    buttonsLayout->addWidget(playButton);
    buttonsLayout->addWidget(pauseButton);
    buttonsLayout->addWidget(stopButton);
    buttonsLayout->addWidget(captureButton);
    buttonsLayout->addWidget(quitButton);
    buttonsLayout->addStretch();
}
