#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open(QImage qimage)
{
    picture = qimage;
    ui->setupUi(this);
    ui->imageDisplay->setPixmap(QPixmap::fromImage(picture));
}

void MainWindow::setTime(int time)
{
    this->timeMS = time;
}

int MainWindow::getTime()
{
    return this->timeMS;
}
