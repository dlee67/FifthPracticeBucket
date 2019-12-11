#include "mainwindow.h"
#include "ui_mainwindow.h" // Enables me to call setupUi()

#include <QDebug> // It's, like, the logcat from Android.
#include <QInputDialog>

//https://doc.qt.io/qt-5/qwidget.html
MainWindow::MainWindow(QWidget *parent) // base class of all user interface object, QWidget inherits QObject, enabling this class to call connect.
    : QMainWindow(parent) // Provides the main application window, it's like the activity from Android.
    , ui(new Ui::MainWindow)
{
    //setupUi() creates actual instances of widgets; meaning, it's like the setContentView
    ui->setupUi(this); // Arrow operator dereferences the object, and grabs the member in it.
    // Specifies which signal is linked to which slot.
    // ui_mainwindow.h is the ui I made in the mainwindow.ui.
    connect(ui->addTaskButton, &QPushButton::clicked,
        this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//https://www.geeksforgeeks.org/scope-resolution-operator-in-c/
// Wait, but there is only one addTask()?
void MainWindow::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this,
        tr("Add task"),
        tr("Task name"),
        QLineEdit::Normal,
        tr("Untitled task"),               &ok);
    if (ok && !name.isEmpty()) {
        qDebug() << "Adding new task";
        Task* task = new Task(name);
        mTasks.append(task);
        ui->tasksLayout->addWidget(task);
    }
}
