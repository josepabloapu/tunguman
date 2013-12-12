#include "mainwindow.h"
#include "secondwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow m;
    m.show();

    SecondWindow s;
    s.show;

    return a.exec();
}
