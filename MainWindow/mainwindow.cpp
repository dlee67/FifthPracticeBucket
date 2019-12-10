#include "mainwindow.h"
#include "ui_mainwindow.h" // Enables me to call setupUi()

#include <QDebug> // It's, like, the logcat from Android.

//https://doc.qt.io/qt-5/qwidget.html
MainWindow::MainWindow(QWidget *parent) // base class of all user interface object, QWidget inherits QObject, enabling this class to call connect.
    : QMainWindow(parent) // Provides the main application window, it's like the activity from Android.
    , ui(new Ui::MainWindow)
{
    //setupUi() creates actual instances of widgets; meaning, it's like the setContentView
    ui->setupUi(this); // Arrow operator dereferences the object, and grabs the member in it.
    // Specifies which signal is linked to which slot.
    // ui_mainwindow.h is the ui I made in the mainwindow.ui.
    connect(ui->addTaskButton, &QPushButton::clicked, //&QPushButton::clicked is like the event name?
        QApplication::instance(), &QApplication::quit); //Same for the &QApplication::quit
}

MainWindow::~MainWindow()
{
    delete ui;
}

//https://www.geeksforgeeks.org/scope-resolution-operator-in-c/
// Wait, but there is only one addTask()?
void MainWindow::addTask()
{
    qDebug() << "User clicked on the button!";
}
