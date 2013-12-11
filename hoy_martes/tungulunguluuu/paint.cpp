    /*PaintArea::PaintArea (QWidget *parent): QWidget (parent){

	drawingTool = PEN;
	drawing = false;
}
void PaintArea::mousePressEvent (QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
    	startPoint = endPoint = event -> pos();
    	drawing = true;
	}
}

void PaintArea::mouseMoveEvent (QMouseEvent *event)////////////////////AQUI////////////////////////
{
	if ((event->buttons() & Qt::LeftButton) && drawing)
	{
    	endPoint = event -> pos();
		//x[i]=event->pos().x;
		//y[i]=event->pos().y;i++;

    	switch (drawingTool)
    	{
        	case PEN:
        	drawLine ();
        	startPoint = endPoint;
        	update ();
        	break;
    	}
	}
}

void PaintArea::mouseReleaseEvent (QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && drawing)
	{
    	endPoint = event -> pos();

    	switch (drawingTool)
    	{
        	case PEN:
        	drawLine ();
        	update ();
        	break;
    	}

            	drawing = false;
	}
}

void PaintArea::drawLine ()
{
	QPainter painter (&image);
	painter.setPen (pen);
	painter.drawLine (startPoint,endPoint);
}

*/
