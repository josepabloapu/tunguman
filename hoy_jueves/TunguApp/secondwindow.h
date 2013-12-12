#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QRect>
#include <QPainter>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = 0);
    ~SecondWindow();
    void open(QImage qimage);
    QPixmap pixmap;
    void Main (QPixmap, int,int);
    QPainter painter;
    bool variable;
    bool eventFilter(QObject *obj, QEvent *event);
    void setTime(int);
    int getTime();

private:
    Ui::SecondWindow *ui;
    int timeMS;
};

#endif // SECONDWINDOW_H
