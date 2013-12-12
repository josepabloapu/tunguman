#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void open(QImage);
    void setTime(int);
    int getTime();

private:
    Ui::MainWindow *ui;
    QImage picture;
    int timeMS;
};

#endif // MAINWINDOW_H
