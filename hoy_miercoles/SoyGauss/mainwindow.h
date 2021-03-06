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
    void open(QPixmap, int, int);
    bool mousePressEventPaint(QObject *obj, QEvent *event);
    void setpixmap(QPixmap* image_pixmap);
    QString coordenadas;
    QPixmap pixmap;
    bool variable;
    int Height;
    int Width;
    int x; int y;
    QPainter painter;
    int scaleH;
    int scaleW;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;

    bool eventFilter(QObject *obj, QEvent *event);

private:

    void scaleImage(double factor);
    void zoomOut();
    void zoomIn();
};

#endif // MAINWINDOW_H
