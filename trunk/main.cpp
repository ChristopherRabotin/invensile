#include <QtGui/QApplication>
#include <QDesktopWidget>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    /* Moves the window to the center of the screen. */
    w.move(qApp->desktop()->availableGeometry(qApp->desktop()).center()-w.rect().center());
    return a.exec();
}
