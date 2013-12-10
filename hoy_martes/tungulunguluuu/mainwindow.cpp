#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTransform>
#include <QVBoxLayout>
#include <QVector>
#include <QtDebug>

#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QMouseEvent>
#include <iostream>
#include <QtGui>
#include <QString>

using namespace std;



bool variable = false;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){

    QVector<int> x;
    QVector<int> y;
    coordenadas = "";

}

MainWindow::~MainWindow(){
    delete ui;
}


//Tracking cursor position
bool MainWindow::eventFilter(QObject *obj, QEvent *event){



    if (event->type() == QEvent::MouseMove){

        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        statusBar()->showMessage(QString("Cursor position (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));

        if (variable == true){
            
            coordenadas+= "Pos X: ";
             coordenadas+= QString::number(mouseEvent->pos().x());
              coordenadas+= "Pos Y: ";
               coordenadas+= QString::number(mouseEvent->pos().y());


            qDebug() << coordenadas;


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

void MainWindow::open(QImage foto)

{
    QImage photo = foto;

    QPixmap pixmap(QPixmap::fromImage(photo));
    QIcon icon(pixmap);
    ui->setupUi(this);

    ui->button_save->setIcon(icon);
    ui->button_save->setIconSize(pixmap.rect().size()*0.077);

    ui->image_view->setStyleSheet("background-color: white");
    ui->display_frame->setText("17");
    ui->image_view->setMouseTracking(true);
    ui->image_view->installEventFilter(this);

    }

////////////////////////////////////////////////////////////////////////////////////////////////


void MainWindow::setpixmap(QPixmap* image_pixmap){

    ui->image_view->setPixmap(*image_pixmap);
    ui->image_view->show();

}


/*
bool MainWindow::mousePressEventPaint(QObject *obj, QEvent *event){




}


    int i=0;
    QVector<int> x;
    QVector<int> y;
    qDebug() << " hola mundo ";

    while (event->button() == Qt::LeftButton){
        x[i]=event->pos().x();
        y[i]=event->pos().y();
        i++;

        qDebug() << x[i] << " espacio " << y[i];

        if (event->button() == Qt::RightButton)
            return true;
    }

    if (event->button() == Qt::MidButton){
       x.erase (x.begin(), x.end());
       y.erase (x.begin(), x.end());
    }

    return false;
}
*/

    // if (event->button() == Qt::MidButton && qevent->button() == Qt::LeftButton){

         // while(i>0){

          //x[i]=0;
          //y[i]=0;
          //i--;

          //}

         //return false;

     //}


/*************************/// Funciones de Botones /**********************************+////

void MainWindow::zoomIn()

{
    scaleImage(1.25);
}

void MainWindow::zoomOut()
{
    scaleImage(0.8);
}

void MainWindow::scaleImage(double factor)

{
    int scaleFactor = 1;

    Q_ASSERT(imageLabel->pixmap());
    scaleFactor *= factor;
    //imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    // Boton // zoomInAct->setEnabled(scaleFactor < 3.0);
    // Boton // zoomOutAct->setEnabled(scaleFactor > 0.333);
}
