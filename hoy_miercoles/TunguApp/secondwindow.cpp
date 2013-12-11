#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
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
