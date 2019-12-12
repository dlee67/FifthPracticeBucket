#include "mainwindow.h"
#include "ui_mainwindow.h" // Enables me to call setupUi()

#include <QDebug> // It's, like, the logcat from Android.
#include <QInputDialog>

//https://doc.qt.io/qt-5/qwidget.html
MainWindow::MainWindow(QWidget *parent) // base class of all user interface object, QWidget inherits QObject, enabling this class to call connect.
    : QMainWindow(parent) // Provides the main application window, it's like the activity from Android.
    , ui(new Ui::MainWindow),
    mTasks()
{
    //setupUi() creates actual instances of widgets; meaning, it's like the setContentView
    ui->setupUi(this); // Arrow operator dereferences the object, and grabs the member in it.
    // Specifies which signal is linked to which slot.
    // ui_mainwindow.h is the ui I made in the mainwindow.ui.
    connect(ui->addTaskButton, &QPushButton::clicked,
        this, &MainWindow::addTask);
    updateStatus();
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
        connect(task, &Task::removed,
               this, &MainWindow::removeTask);
        connect(task, &Task::statusChanged, this,
                       &MainWindow::taskStatusChanged);
        mTasks.append(task);
        ui->tasksLayout->addWidget(task);
        updateStatus();
    }
}

void MainWindow::removeTask(Task* task)
{
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    delete task;
    updateStatus();
}

void MainWindow::taskStatusChanged(Task* /*task*/)
{
    updateStatus();
}

void MainWindow::updateStatus()
{
    int completedCount = 0;
    for(auto t : mTasks)  { // Appearantly, for each is relatively new in C++ because it came out in C++11.
        if (t->isCompleted()) {
            completedCount++;
        }
    }
    int todoCount = mTasks.size() - completedCount;

    ui->statusLabel->setText(QString("Status: %1 todo / %2 completed")
                             .arg(todoCount)
                             .arg(completedCount));
}
