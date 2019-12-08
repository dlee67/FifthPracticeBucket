#ifndef HELLO_H
#define HELLO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class hello; }
QT_END_NAMESPACE

class hello : public QMainWindow
{
    Q_OBJECT

public:
    hello(QWidget *parent = nullptr);
    ~hello();

private:
    Ui::hello *ui;
};
#endif // HELLO_H
