/********************************************************************************
** Form generated from reading UI file 'hello.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLO_H
#define UI_HELLO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hello
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *hello)
    {
        if (hello->objectName().isEmpty())
            hello->setObjectName(QString::fromUtf8("hello"));
        hello->resize(800, 600);
        centralwidget = new QWidget(hello);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        hello->setCentralWidget(centralwidget);
        menubar = new QMenuBar(hello);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        hello->setMenuBar(menubar);
        statusbar = new QStatusBar(hello);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        hello->setStatusBar(statusbar);

        retranslateUi(hello);

        QMetaObject::connectSlotsByName(hello);
    } // setupUi

    void retranslateUi(QMainWindow *hello)
    {
        hello->setWindowTitle(QApplication::translate("hello", "hello", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hello: public Ui_hello {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLO_H
