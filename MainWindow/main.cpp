#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Manages the GUI application's control flow.
    MainWindow w;
    w.show();
    return a.exec(); // Enters the main event loop and waits until exit() is called.
}
