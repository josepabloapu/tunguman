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
    void Crop();
    QPixmap pixmap;
    void Main (QPixmap);
    QPainter painter;
    bool variable;
    bool eventFilter(QObject *obj, QEvent *event);

private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
