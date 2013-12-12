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
    QRect getRect(QEvent*);
    int xi;
    int yi;
    int xf;
    int yf;
    QPainter painter;

private:
    bool variable;
    int timeMS;
    QLabel* imageView;
    QRect rectangle;
    QPixmap pixmap;

signals:

public slots:

};

#endif // IMAGECROP_H
