#include "mainwindow.h"
#include "secondwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QPainter>
#include <QEvent>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>

int Height=30;
int Width=100;
int x=-1; int y=-1;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPainter painter;

    QSqlDatabase db = QSqlDatabase::addDatabase( "QMYSQL" );
    QSqlQuery qry;

    db.setHostName( "localhost" );
    db.setDatabaseName( "test" );
    db.setUserName( "root" );
    db.setPassword( "root" );

    if(!db.open()){
            qDebug() << db.lastError();
            qFatal( "Failed to connect." );
     }

    else qDebug( "Connected!" );

    qry.prepare("CREATE TABLE IF NOT EXISTS names (id INTEGER UNIQUE KEY AUTO_INCREMENT, time INTEGER, name VARCHAR(30), team VARCHAR(30), number INTEGER, xpos INTEGER, ypos INTEGER)");
    if(!qry.exec()) qDebug() << qry.lastError();
    else qDebug() << "Table created!";
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
    pixmap.scaled(Width,Height,Qt::KeepAspectRatio);
    ui->image_view->setMouseTracking(true);
    ui->image_view->installEventFilter(this);

    ui->dropdown_team->addItem("Home");
    ui->dropdown_team->addItem("Away");
}

void MainWindow::open(QPixmap pix, int h, int w)
{
    ui->setupUi(this);

    ui->image_view->setScaledContents(true);

    pixmap = pix;

    pixmap.scaled(Width,Height,Qt::KeepAspectRatio);

    ui->image_view->setPixmap(pixmap);
    ui->image_view->setMouseTracking(true);
    ui->image_view->installEventFilter(this);

    scaleH = 251/h;
    scaleW = 511/w;

}

bool MainWindow::eventFilter(QObject *obj, QEvent *event){

    if (event->type() == QEvent::MouseMove){

        mouseEvent = static_cast<QMouseEvent*>(event);
        statusBar()->showMessage(QString("Cursor position (%1,%2)").arg(mouseEvent->pos().x()).arg(mouseEvent->pos().y()));

        QSqlQuery qry;

        qry.prepare("INSERT INTO names (time, name, team, number, xpos, ypos) VALUES (:time, :name, :team, :number, :xpos, :ypos)");
        qry.bindValue(":time",this->timeMS);
        qry.bindValue(":name",ui->input_name->text());
        qry.bindValue(":team",ui->dropdown_team->currentText());
        qry.bindValue(":number",ui->input_number->text());
        qry.bindValue(":xpos",mouseEvent->pos().x());
        qry.bindValue(":ypos",mouseEvent->pos().y());

        if(!qry.exec()) qDebug() << qry.lastError();
        else qDebug("Inserted!");

        if (variable == true)
        {
           int cosx =0;
           int cosy =0;
                if(x!=-1 && y!=-1)
                {
                    if(x!=0 && y!=0)
                    {
                        qDebug() << x;
                        qDebug() << "----";
                        qDebug() << y;

                        painter.begin(&pixmap);
                        QColor Color = QColor(235,20,230,255);
                        QPen pen(Color, 8, Qt::SolidLine);
                        painter.setPen(pen);
                        painter.drawPoint((3*mouseEvent->pos().x()/scaleW) + cosx, (4.5*mouseEvent->pos().y()/scaleH) + cosy);
                        ui->image_view->setPixmap(pixmap);
                    }
                }

                coordenadas+= "Pos X: ";
                coordenadas+= QString::number(mouseEvent->pos().x());
                coordenadas+= "Pos Y: ";
                coordenadas+= QString::number(mouseEvent->pos().y());

                qDebug() << coordenadas;
                x = mouseEvent->pos().x();
                y = mouseEvent->pos().y();
        }
    }

    if (event->type() == QEvent::MouseButtonPress){

        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);

        if (mouseEvent->button() == Qt::LeftButton)
            variable=true;

        if (mouseEvent->button() == Qt::RightButton)
        {
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

    Q_ASSERT(image_view->pixmap());
    scaleFactor *= factor;

}

void MainWindow::on_button_save_clicked()
{
    QSqlQuery qry;

    qry.prepare("INSERT INTO names (time, name, team, number, xpos, ypos) VALUES (:time, :name, :team, :number, :xpos, :ypos)");
    qry.bindValue(":time",this->timeMS);
    qry.bindValue(":name",ui->input_name->text());
    qry.bindValue(":team",ui->dropdown_team->currentText());
    qry.bindValue(":number",ui->input_number->text());
    qry.bindValue(":xpos",mouseEvent->pos().x());
    qry.bindValue(":ypos",mouseEvent->pos().y());

    if(!qry.exec()) qDebug() << qry.lastError();
    else qDebug("Inserted!");
}

void MainWindow::setTime(int time)
{
    this->timeMS = time;
}
