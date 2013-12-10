#ifndef MOVIEPLAYER_H
#define MOVIEPLAYER_H

#include <QWidget>

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


class MoviePlayer : public QWidget {
    Q_OBJECT

signals:
    // define mouseClick signal
    void mouseClickEvent();

public:
    MoviePlayer(QWidget *parent = 0);
    void openFile(const QString &fileName);

    QPixmap* mousePressEventZoom(QMouseEvent *qevent, QWidget* parent);


    //void mouseReleaseEvent ( QMouseEvent * e );
    //void mousePressEvent ( QMouseEvent * e );

private slots:
    void open();
    void goToFrame(int frame);
    void fitToWindow();
    void updateButtons();
    void updateFrameSlider();
    void photoButtonClicked();


private:
    void createControls();
    void createButtons();

    QString currentMovieDirectory;
    QLabel *movieLabel;
    QMovie *movie;
    QToolButton *photoButton;
    QToolButton *openButton;
    QToolButton *playButton;
    QToolButton *pauseButton;
    QToolButton *stopButton;
    QToolButton *quitButton;
    QCheckBox *fitCheckBox;
    QSlider *frameSlider;
    QSpinBox *speedSpinBox;
    QLabel *frameLabel;
    QLabel *speedLabel;

    QGridLayout *controlsLayout;
    QHBoxLayout *buttonsLayout;
    QVBoxLayout *mainLayout;



    QDialog *newWindow;
    QToolButton *newquitButton;


};

#endif
