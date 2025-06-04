#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Filmstudio filmstudio;
    MainWindow w(&filmstudio);
    w.show();
    return a.exec();
}
