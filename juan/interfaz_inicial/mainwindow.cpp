#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int i;
    QPixmap pixmap("/home/juan/interfaz_inicial/save.png");
    QIcon icon(pixmap);
    ui->setupUi(this);

    for(i=0; i<100; i++) ui->dropdown_number->addItem(QString::number(i));

    ui->button_save->setIcon(icon);
    ui->button_save->setIconSize(pixmap.rect().size()*0.077);
    ui->button_zoomout_2 ->setStyleSheet("background-color: rgb(255, 0, 0)");
    ui->image_view->setStyleSheet("background-image:url(/home/juan/interfaz_inicial/fut.jpg)");
}

MainWindow::~MainWindow()
{
    delete ui;
}
