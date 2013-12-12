#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "mainwindow.h"
#include <QPainter>
#include <QEvent>
#include <QPixmap>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>

bool variable = false;
QRect rect;
int xi, yi, xf, yf;




SecondWindow::SecondWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::SecondWindow)
{
    ui->setupUi(this);


}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::open(QImage qimage)

{


    ui->setupUi(this);
    QImage picture = qimage;
    ui->image_view->setScaledContents(true);
    pixmap = QPixmap::fromImage(picture);



    ui->image_view->setPixmap(pixmap);
    ui->image_view->setMouseTracking(true);
    ui->image_view->installEventFilter(this);
}


bool SecondWindow::eventFilter(QObject *obj, QEvent *event){


         QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);

            if (event->type() == QEvent::MouseButtonPress){

                 qDebug() << "--**";


                if (mouseEvent->button() == Qt::LeftButton){

                      xi = mouseEvent->pos().x();
                      yi = mouseEvent->pos().y();

                      qDebug() << xi;
                      qDebug() << "----";
                      qDebug() << yi;

                      variable=true;

                 }

                 if(variable==true && mouseEvent->button() == Qt::MidButton){

                     xf = mouseEvent->pos().x();
                     yf = mouseEvent->pos().y();

                      QRect rect = QRect(xi,yi,xf,yf);

                        painter.begin(&pixmap);
                        QColor Color = QColor(200,0,0,255);
                        QPen pen(Color, 8, Qt::SolidLine);
                        painter.setPen(pen);
                        painter.drawRect(rect);

                        ui->image_view->setPixmap(pixmap);

                 }


                   if(mouseEvent->button() == Qt::RightButton){
                            QRect rect = QRect(xi,yi,xf,yf);
                            variable = false;
                            QPixmap crop = pixmap.copy (rect);


                           int h = yf - yi;
                           int w = xf - xi;

                           Main(crop, h, w);

                              return true;

                      }

            }



    return false;

    }

void SecondWindow::Main (QPixmap pix, int h, int w){

    MainWindow* mainwindow = new MainWindow();
    mainwindow->open(pix, h, w);
    mainwindow->setTime(this->getTime());
    mainwindow->show();


}

void SecondWindow::setTime(int time)
{
    this->timeMS = time;
}

int SecondWindow::getTime()
{
    return this->timeMS;
}












