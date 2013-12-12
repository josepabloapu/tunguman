#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void open(QImage);
    bool mousePressEventPaint(QObject *obj, QEvent *event);
    void setpixmap(QPixmap* image_pixmap);
    QString coordenadas;
    QPixmap pixmap;
    bool variable;
    int Height;
    int Width;
    int x; int y;
    QPainter painter;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
<<<<<<< HEAD
    void open(QImage);
    void setTime(int);
    int getTime();

private:
    Ui::MainWindow *ui;
    QImage picture;
    int timeMS;
=======
    Ui::MainWindow *ui;

    bool eventFilter(QObject *obj, QEvent *event);

private:

    void scaleImage(double factor);
    void zoomOut();
    void zoomIn();
>>>>>>> 347aba52181178afd1c7e84f4892d67d01918223
};

#endif // MAINWINDOW_H
