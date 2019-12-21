#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QDebug>

#include <iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Some errors won't go away if I don't build because the ui_MainWindow
    // only gets populated with addional widgets after build.
    // https://doc.qt.io/qt-5/qobject.html#connect-4
    // connect() has many different overloaded parameters.
    connect(ui->saySomething, &QPushButton::clicked,
      this, &MainWindow::incrementCounter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow:: saySomething() {
    qDebug() << "Something";
}

void MainWindow::incrementCounter() {
    // ui is the entity that holds everything in *.ui file.
    ui->counter->setText(QString("%1").arg(++MainWindow::count));
}
