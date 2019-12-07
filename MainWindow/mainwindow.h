#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    // Allows us to own signals/slots, it's something meta in Qt.
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); // Widgets are like Android's view ... why didn't Andy Rubin name views widgets?
    ~MainWindow(); //Squigly represents deconstructor.

private:
    Ui::MainWindow *ui; //Windows are essentially activities in Qt, through the left variable, I can interact with the window's contents (widgets).
};
#endif // MAINWINDOW_H
