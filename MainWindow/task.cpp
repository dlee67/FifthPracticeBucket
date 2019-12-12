#include "task.h"
#include "ui_task.h"

#include <QDebug>
#include <QInputDialog>

Task::Task(const QString& name, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
    setName(name);
    connect(ui->editButton, &QPushButton::clicked, this, &Task::rename);
    connect(ui->removeButton, &QPushButton::clicked,
    // The below is how lambdas are implemented in C++,
    // which is the anonymous inline function.
          [this] { // [] Defines what variables will be visible inside the lambda scope.
            emit removed(this); // emit is a Qt macro that will trigger the connected slot.
          });
    connect(ui->checkbox, &QCheckBox::toggled,
        this, &Task::checked);
// Lambda is powerful enough to a point that they can be directly be fed into stdin.
//    connect(ui->removeButton, &QPushButton::clicked, [this, name] {
//        qDebug() << "Trying to remove" <<
//            [] (const QString& taskName) -> QString {
//                return "-------- " + taskName.toUpper();
//        }(name);
//        emit removed(this);
//    });
}

Task::~Task()
{
    delete ui;
}

void Task::setName(const QString& name)
{
    ui->checkbox->setText(name);
}

QString Task::name() const
{
    return ui->checkbox->text();
}

bool Task::isCompleted() const
{
   return ui->checkbox->isChecked();
}

void Task::rename()
{
    bool ok;
    QString value = QInputDialog::getText(this, tr("Edit task"),
                                          tr("Task name"),
                                          QLineEdit::Normal,
                                          this->name(), &ok);
    if (ok && !value.isEmpty()) {
        setName(value);
    }
}

void Task::checked(bool checked)
{
    QFont font(ui->checkbox->font());
    font.setStrikeOut(checked);
    ui->checkbox->setFont(font);
    emit statusChanged(this);
}
