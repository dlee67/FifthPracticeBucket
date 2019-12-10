/********************************************************************************
** Form generated from reading UI file 'task.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Task
{
public:
    QPushButton *editButton;
    QCheckBox *checkbox;
    QPushButton *removeButton;

    void setupUi(QWidget *Task)
    {
        if (Task->objectName().isEmpty())
            Task->setObjectName(QString::fromUtf8("Task"));
        Task->resize(400, 300);
        editButton = new QPushButton(Task);
        editButton->setObjectName(QString::fromUtf8("editButton"));
        editButton->setGeometry(QRect(210, 20, 89, 25));
        checkbox = new QCheckBox(Task);
        checkbox->setObjectName(QString::fromUtf8("checkbox"));
        checkbox->setGeometry(QRect(20, 20, 92, 23));
        removeButton = new QPushButton(Task);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        removeButton->setGeometry(QRect(300, 20, 89, 25));

        retranslateUi(Task);

        QMetaObject::connectSlotsByName(Task);
    } // setupUi

    void retranslateUi(QWidget *Task)
    {
        Task->setWindowTitle(QApplication::translate("Task", "Form", nullptr));
        editButton->setText(QApplication::translate("Task", "Edit", nullptr));
        checkbox->setText(QApplication::translate("Task", "Buy Milk", nullptr));
        removeButton->setText(QApplication::translate("Task", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Task: public Ui_Task {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
