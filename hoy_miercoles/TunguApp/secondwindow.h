#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QRect>

namespace Ui2 {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = 0);
    ~SecondWindow();
    void open(QImage qimage);
    QRect rect;
    QPixmap Crop();
    QRect getRect(QEvent*);
    QPixmap pixmap;
    bool variable;

private:
    Ui2::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
