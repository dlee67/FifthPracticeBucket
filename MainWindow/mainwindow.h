// Headers constains the foward declarations.
// These are called include guards.
// #ifndeg checks if MAINWINDOW_H is defined.
#ifndef MAINWINDOW_H
// If not, define it.
#define MAINWINDOW_H

#include <QMainWindow>

// QT_BEGIN_NAMESPACE is their safe guard mechanism for their namespace.
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    // Allows us to own signals/slots, it's something meta in Qt.
    // https://doc.qt.io/archives/qq/qq16-dynamicqobject.html
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); // Widgets are like Android's view ... why didn't Andy Rubin name views widgets?
    ~MainWindow(); //Squigly represents the deconstructor, and this particular deconstructor is implemented in mainwindow.cpp.

// slot is a function that will be called when the signal is triggered,
// and signal is message sent by an object.
// The below is specfic to Qt, public keyword doesn't normally gets used with slots keyword.
public slots:
    void addTask();

private:
    Ui::MainWindow *ui; //Windows are essentially activities in Qt, through the left variable, I can interact with the window's contents (widgets).
};
#endif // Ends the #ifndef scope.
// MAINWINDOW_H
