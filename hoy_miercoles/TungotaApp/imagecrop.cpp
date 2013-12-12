#include "imagecrop.h"
#include <QPainter>
#include <QEvent>
#include <QMouseEvent>

ImageCrop::ImageCrop(QWidget *parent) :
    QWidget(parent)
{
    imageView = new QLabel;
    QRect rectangle;
    QPixmap pixmap;
    QPainter painter;
    variable = false;
    xi = -1;
    yi = -1;
    xf = -1;
    yf = -1;
}

void ImageCrop::open(QImage qimage)

{
    //QImage picture = qimage;
    imageView->setScaledContents(true);
    //pixmap->fromImage(qimage);
    imageView->setPixmap(QPixmap::fromImage(qimage));
    imageView->setMouseTracking(true);
    imageView->installEventFilter(this);
    imageView->show();
    QPixmap crop = ImageCrop::crop();
}

void ImageCrop::setTime(int time)
{
    this->timeMS = time;
}

int ImageCrop::getTime()
{
    return this->timeMS;
}

QPixmap ImageCrop::crop()
{
    QEvent* event;
    rectangle = getRect(event);
    QPixmap crop = pixmap.copy(rectangle);
    return crop;

}




QRect ImageCrop::getRect(QEvent* event){
    if (event->type() == QEvent::MouseMove)
    {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton)
        {
            xi = mouseEvent->pos().x();
            yi = mouseEvent->pos().y();
            variable=true;
        }

        if(variable==true){
            xf = mouseEvent->pos().x();
            yf = mouseEvent->pos().y();

            painter.begin(&pixmap);
            QColor Color = QColor(200,20,230,255);
            QPen pen(Color, 8, Qt::SolidLine);
            painter.setPen(pen);
            painter.drawLine(xi,yi,xf,yi);
            painter.drawLine(xi,yi,xi,yf);
            painter.drawLine(xf,yi,xi,yf);
            painter.drawLine(xi,yf,xf,yi);

            imageView->setPixmap(pixmap);


        if(mouseEvent->button() == Qt::RightButton){

            variable = false;

            return QRect(xi,yi,xf,yf);

        }

    }

    }
}

