#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPainter>
#include <QEvent>
#include <QDebug>

int Height=30;
int Width=200;
int x=-1; int y=-1;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPainter painter;



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open(QImage qimage)

{

    ui->setupUi(this);


    QImage picture = qimage;

    ui->image_view->setScaledContents(true);

    pixmap = QPixmap::fromImage(picture);


    pixmap.scaled(Width,Height,Qt::KeepAspectRatio);


    ui->image_view->setPixmap(pixmap);
    ui->image_view->setMouseTracking(true);
    ui->image_view->installEventFilter(this);

    }

bool MainWindow::eventFilter(QObject *obj, QEvent *event){


    if (event->type() == QEvent::MouseMove){

        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);

        statusBar()->showMessage(QString("Cursor position (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));


        if (variable == true){

            int calibrarx =85; //ERROR AQUI ES UNA APROXIMACION HAY QUE CUADRAR LOS 2 MARCOS DE REFERENCIA!!!!***************************
            int calibrary =96;

            if(x!=-1 && y!=-1){
               if(x!=0 && y!=0){
            qDebug() << x;
            qDebug() << "----";
            qDebug() << y;

           painter.begin(&pixmap);
           QColor Color = QColor(235,20,230,255);
           QPen pen(Color, 8, Qt::SolidLine);
           painter.setPen(pen);
           painter.drawLine(x+calibrarx,y+calibrary,mouseEvent->pos().x()+calibrarx,mouseEvent->pos().y()+calibrary);
           ui->image_view->setPixmap(pixmap);

            }

          }

            coordenadas+= "Pos X: ";
             coordenadas+= QString::number(mouseEvent->pos().x());
              coordenadas+= "Pos Y: ";
               coordenadas+= QString::number(mouseEvent->pos().y());


            qDebug() << coordenadas;

            x=mouseEvent->pos().x();

            y= mouseEvent->pos().y();


        }
      }

    if (event->type() == QEvent::MouseButtonPress){

        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        if (mouseEvent->button() == Qt::LeftButton){

                variable=true;


       }


        if (mouseEvent->button() == Qt::RightButton){

                variable=false;
                qDebug() << "false";
       }


      }


    return false;
}



/*************************/// Funciones de Botones /**********************************+////

void MainWindow::zoomIn(){


    Height+=30;
    Width+=30;

    pixmap.scaled(Width,Height,Qt::KeepAspectRatio);
    ui->image_view->setPixmap(pixmap);


}

void MainWindow::zoomOut(){


    Height-=30;
    Width-=30;

    pixmap.scaled(Width,Height,Qt::KeepAspectRatio);
    ui->image_view->setPixmap(pixmap);

}

void MainWindow::scaleImage(double factor)

{
    int scaleFactor = 1;

    Q_ASSERT(imageLabel->pixmap());
    scaleFactor *= factor;

}
