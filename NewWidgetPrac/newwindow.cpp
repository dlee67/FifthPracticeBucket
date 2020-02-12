#include "newwindow.h"
#include "ui_newwindow.h"
#include "mainwindow.h"

NewWindow::NewWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::NewWindow)
{
    ui->setupUi(this);
}

NewWindow::~NewWindow()
{
    delete ui;
}

void NewWindow::on_pushButton_clicked()
{
    close();
    MainWindow* mainWindow = new MainWindow();
    mainWindow->show();
}
