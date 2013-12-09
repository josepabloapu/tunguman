#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

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
    int i;
    QVector<int> x;
    QVector<int> y;

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
