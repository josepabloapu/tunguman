
#include <QtGui>
#include <QImage>
#include <QRect>
#include <QtDebug>
#include<QMouseEvent>

#include "imageviewer.h"
#include "movieplayer.h"
#include "mainwindow.h"
#include "paintarea.h"

QImage *photo = new QImage();


MoviePlayer::MoviePlayer(QWidget *parent)
    : QWidget(parent){

    movie = new QMovie(this);
    movie->setCacheMode(QMovie::CacheAll);

    movieLabel = new QLabel(tr("No movie loaded"));
    movieLabel->setAlignment(Qt::AlignCenter);
    movieLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    movieLabel->setBackgroundRole(QPalette::Dark);
    movieLabel->setAutoFillBackground(true);
    movieLabel->installEventFilter(this);
    movieLabel->setMouseTracking(true);
    currentMovieDirectory = "movies";

    createControls();
    createButtons();

    connect(movie, SIGNAL(frameChanged(int)), this, SLOT(updateFrameSlider()));
    connect(movie, SIGNAL(stateChanged(QMovie::MovieState)),this, SLOT(updateButtons()));
    connect(fitCheckBox, SIGNAL(clicked()), this, SLOT(fitToWindow()));
    connect(frameSlider, SIGNAL(valueChanged(int)), this, SLOT(goToFrame(int)));
    connect(speedSpinBox, SIGNAL(valueChanged(int)), movie, SLOT(setSpeed(int)));


    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(movieLabel);
    mainLayout->addLayout(controlsLayout);
    mainLayout->addLayout(buttonsLayout);
    setLayout(mainLayout);

    updateFrameSlider();
    updateButtons();

    setWindowTitle(tr("Tungu Player"));
    resize(600, 400);


}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void MoviePlayer::photoButtonClicked() {
    MainWindow *mainWindow;
    mainWindow = new MainWindow();
    //QMouseEvent *event;
    // QPixmap* zoom;
    //zoom = mousePressEventZoom(event, movieLabel);
    //    mainWindow->setpixmap(zoom);
   mainWindow->open(movie->currentImage());
    //PaintArea* paintWindow = new PaintArea(mainWindow);
    //paintWindow->setImage(movie->currentImage());
    mainWindow->show();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    QPixmap* MoviePlayer::mousePressEventZoom(QMouseEvent *qevent, QWidget* parent){

        int* xi=0; int* yi=0;
        int* xf=0; int* yf=0;


        const QRect *Selection = new QRect();



        if (qevent->button() == Qt::LeftButton){

            movieLabel->mapFromGlobal(QCursor::pos()).x();
                *xi = QCursor::pos().x();
            movieLabel->mapFromGlobal(QCursor::pos()).y();
                *yi = QCursor::pos().y();

            qDebug() << *xi << "-" << *yi;

       }

        if (qevent->button() == Qt::RightButton){

            movieLabel->mapFromGlobal(QCursor::pos()).x();
                *xf = QCursor::pos().x();
            movieLabel->mapFromGlobal(QCursor::pos()).y();
                *yf = QCursor::pos().y();

            Selection->getCoords(xi, yi, xf, yf);

            QPixmap* Zoom = new QPixmap ();

           *Zoom = QPixmap::grabWidget (parent,*Selection);

           return Zoom;

            qDebug() << *xf << "-" << *yf;
       }



    }





///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////7



void MoviePlayer::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open a Movie"), currentMovieDirectory);
    if (!fileName.isEmpty())
        openFile(fileName);
}

void MoviePlayer::openFile(const QString &fileName)
{
    currentMovieDirectory = QFileInfo(fileName).path();

    movie->stop();
    movieLabel->setMovie(movie);
    movie->setFileName(fileName);
    movie->start();

    updateFrameSlider();
    updateButtons();
}

void MoviePlayer::goToFrame(int frame)
{
    movie->jumpToFrame(frame);
}

void MoviePlayer::fitToWindow()
{
    movieLabel->setScaledContents(fitCheckBox->isChecked());
}

void MoviePlayer::updateFrameSlider()
{
    bool hasFrames = (movie->currentFrameNumber() >= 0);

    if (hasFrames) {
        if (movie->frameCount() > 0) {
            frameSlider->setMaximum(movie->frameCount() - 1);
        } 

else {

            if (movie->currentFrameNumber() > frameSlider->maximum())
                frameSlider->setMaximum(movie->currentFrameNumber());
        }

        frameSlider->setValue(movie->currentFrameNumber());
    } 

else {

        frameSlider->setMaximum(0);
    }

    frameLabel->setEnabled(hasFrames);
    frameSlider->setEnabled(hasFrames);
}

void MoviePlayer::updateButtons()
{
    playButton->setEnabled(movie->isValid() && movie->frameCount() != 1 && movie->state() == QMovie::NotRunning);
    pauseButton->setEnabled(movie->state() != QMovie::NotRunning);
    pauseButton->setChecked(movie->state() == QMovie::Paused);
    stopButton->setEnabled(movie->state() != QMovie::NotRunning);
}

void MoviePlayer::createControls()
{
    fitCheckBox = new QCheckBox(tr("Fit to Window"));

    frameLabel = new QLabel(tr("Current frame:"));

    frameSlider = new QSlider(Qt::Horizontal);
    frameSlider->setTickPosition(QSlider::TicksBelow);
    frameSlider->setTickInterval(10);

    speedLabel = new QLabel(tr("Speed:"));

    speedSpinBox = new QSpinBox;
    speedSpinBox->setRange(1, 9999);
    speedSpinBox->setValue(100);
    speedSpinBox->setSuffix(tr("%"));

    controlsLayout = new QGridLayout;
    controlsLayout->addWidget(fitCheckBox, 0, 0, 1, 2);
    controlsLayout->addWidget(frameLabel, 1, 0);
    controlsLayout->addWidget(frameSlider, 1, 1, 1, 2);
    controlsLayout->addWidget(speedLabel, 2, 0);
    controlsLayout->addWidget(speedSpinBox, 2, 1);
}

void MoviePlayer::createButtons()
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
    connect(playButton, SIGNAL(clicked()), movie, SLOT(start()));

    pauseButton = new QToolButton;
    pauseButton->setCheckable(true);
    pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    pauseButton->setIconSize(iconSize);
    pauseButton->setToolTip(tr("Pause"));
    connect(pauseButton, SIGNAL(clicked(bool)), movie, SLOT(setPaused(bool)));

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

//recordAction->setShortcut(tr("Ctrl+R"));


    photoButton = new QToolButton;
    photoButton->setIcon(style()->standardIcon(QStyle::SP_ArrowUp));
    photoButton->setIconSize(iconSize);
    photoButton->setToolTip(tr("Photo"));
    photoButton->setShortcut(tr("Z"));
    connect(photoButton, SIGNAL(clicked()), this, SLOT(photoButtonClicked()));

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(openButton);
    buttonsLayout->addWidget(playButton);
    buttonsLayout->addWidget(pauseButton);
    buttonsLayout->addWidget(stopButton);
    buttonsLayout->addWidget(quitButton);
    buttonsLayout->addWidget(photoButton);
    buttonsLayout->addStretch();
}











