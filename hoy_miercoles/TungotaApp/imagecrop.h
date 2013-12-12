#ifndef IMAGECROP_H
#define IMAGECROP_H

#include <QWidget>
#include <QLabel>
#include <QRect>
#include <QPainter>

class ImageCrop : public QWidget
{
    Q_OBJECT
public:
    explicit ImageCrop(QWidget *parent = 0);
    void open(QImage);
    void setTime(int);
    int getTime();
    QPixmap crop();
    QRect getRect();
    QLabel* imageView;
    QRect rectangle;
    QPixmap pixmap;
    QPainter painter;
    int xi, yi, xf, yf;

private:
    bool variable;
    int timeMS;


signals:

public slots:

};

#endif // IMAGECROP_H
