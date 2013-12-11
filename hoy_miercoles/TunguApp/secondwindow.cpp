#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QPainter>



SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    QRect rect;
    QPixmap pixmap;
	bool variable = false;


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

    QPixmap crop = Crop();


}


QPixmap SecondWindow::Crop (){


rect = getRect(QEvent* qevent);

QPixmap crop = pixmap.copy (rect); 

delete ui;

return crop;

}

QRect SecondWindow::getRect(QEvent* event){

    if (event->type() == QEvent::MouseMove){

        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);

	if (mouseEvent->button() == Qt::LeftButton){

		xi = mouseEvent->pos().x();
		yi = mouseEvent->pos().y();
		variable=true;

	}

	if(variable==true){

		xf=mouseEvent->pos().x();
		yf=mouseEvent->pos().y();

           painter.begin(&pixmap);
           QColor Color = QColor(200,20,230,255);
           QPen pen(Color, 8, Qt::SolidLine);
           painter.setPen(pen);
           painter.drawLine(x,y,mouseEvent->pos().x(),y);
           painter.drawLine(x,y,x,mouseEvent->pos().y());
           painter.drawLine(mouseEvent->pos().x(),y,x,mouseEvent->pos().y());
           painter.drawLine(x,mouseEvent->pos().y(),mouseEvent->pos().x(),y);

           ui->image_view->setPixmap(pixmap);


		if(mouseEvent->button() == Qt::RightButton){

			variable = false;

			return QRect(xi,yi,xf,yf);

		}

	}

    }
}






}



