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

void MainWindow::open(QImage foto)

{
    QImage photo = foto;

    QPixmap pixmap(QPixmap::fromImage(photo));
    QIcon icon(pixmap);
    ui->setupUi(this);

    //ui->button_save->setIcon(icon);
    //ui->button_save->setIconSize(pixmap.rect().size()*0.077);

    ui->imageDisplay->setStyleSheet("background-color: white");
    ui->imageDisplay->setMouseTracking(true);
    ui->imageDisplay->installEventFilter(this);

    }
