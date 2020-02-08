/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionClear;
    QAction *action2px;
    QAction *action5px;
    QAction *action10px;
    QAction *actionBlack;
    QAction *actionWhite;
    QAction *actionRed;
    QAction *actionGreen;
    QAction *actionBlue;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuBrush_size;
    QMenu *menuBrush;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QString::fromUtf8("actionClear"));
        action2px = new QAction(MainWindow);
        action2px->setObjectName(QString::fromUtf8("action2px"));
        action5px = new QAction(MainWindow);
        action5px->setObjectName(QString::fromUtf8("action5px"));
        action10px = new QAction(MainWindow);
        action10px->setObjectName(QString::fromUtf8("action10px"));
        actionBlack = new QAction(MainWindow);
        actionBlack->setObjectName(QString::fromUtf8("actionBlack"));
        actionWhite = new QAction(MainWindow);
        actionWhite->setObjectName(QString::fromUtf8("actionWhite"));
        actionRed = new QAction(MainWindow);
        actionRed->setObjectName(QString::fromUtf8("actionRed"));
        actionGreen = new QAction(MainWindow);
        actionGreen->setObjectName(QString::fromUtf8("actionGreen"));
        actionBlue = new QAction(MainWindow);
        actionBlue->setObjectName(QString::fromUtf8("actionBlue"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuBrush_size = new QMenu(menubar);
        menuBrush_size->setObjectName(QString::fromUtf8("menuBrush_size"));
        menuBrush = new QMenu(menubar);
        menuBrush->setObjectName(QString::fromUtf8("menuBrush"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuBrush_size->menuAction());
        menubar->addAction(menuBrush->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionClear);
        menuBrush_size->addAction(action2px);
        menuBrush_size->addAction(action5px);
        menuBrush_size->addAction(action10px);
        menuBrush->addAction(actionBlack);
        menuBrush->addAction(actionWhite);
        menuBrush->addAction(actionRed);
        menuBrush->addAction(actionGreen);
        menuBrush->addAction(actionBlue);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionClear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
        action2px->setText(QApplication::translate("MainWindow", "2px", nullptr));
        action5px->setText(QApplication::translate("MainWindow", "5px", nullptr));
        action10px->setText(QApplication::translate("MainWindow", "10px", nullptr));
        actionBlack->setText(QApplication::translate("MainWindow", "Black", nullptr));
        actionWhite->setText(QApplication::translate("MainWindow", "White", nullptr));
        actionRed->setText(QApplication::translate("MainWindow", "Red", nullptr));
        actionGreen->setText(QApplication::translate("MainWindow", "Green", nullptr));
        actionBlue->setText(QApplication::translate("MainWindow", "Blue", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuBrush_size->setTitle(QApplication::translate("MainWindow", "Brush Size", nullptr));
        menuBrush->setTitle(QApplication::translate("MainWindow", "Brush Color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
