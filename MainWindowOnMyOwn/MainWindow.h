#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    int count = 0;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void saySomething();
    void incrementCounter();
    void changeNumber();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
