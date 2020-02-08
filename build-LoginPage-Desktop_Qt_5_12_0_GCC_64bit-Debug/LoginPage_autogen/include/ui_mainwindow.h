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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *topPanel;
    QHBoxLayout *horizontalLayout;
    QLabel *currentDateTime;
    QSpacerItem *horizontalSpacer;
    QPushButton *restart;
    QPushButton *power;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *logo;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QWidget *loginForm;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *userName;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *password;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow#centralWidget { \n"
"	background: rgba(32, 80, 96, 100); \n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 781, 627));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        topPanel = new QWidget(verticalLayoutWidget);
        topPanel->setObjectName(QString::fromUtf8("topPanel"));
        topPanel->setStyleSheet(QString::fromUtf8("QWidget#topPanel { \n"
"    background-color: qlineargradient(spread:reflect, x1:0.5, y1:0, x2:0, y2:0, stop:0 rgba(91, 204, 233, 100), stop:1 rgba(32, 80, 96, 100));\n"
"}"));
        horizontalLayout = new QHBoxLayout(topPanel);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        currentDateTime = new QLabel(topPanel);
        currentDateTime->setObjectName(QString::fromUtf8("currentDateTime"));

        horizontalLayout->addWidget(currentDateTime);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        restart = new QPushButton(topPanel);
        restart->setObjectName(QString::fromUtf8("restart"));
        restart->setMinimumSize(QSize(55, 55));
        restart->setStyleSheet(QString::fromUtf8("QPushButton#restart {\n"
"	background-color: #27a9e3;\n"
"}\n"
"\n"
"QPushButton:hover { background-color: #66c011; }\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Vist_Foundation_Logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        restart->setIcon(icon);
        restart->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(restart);

        power = new QPushButton(topPanel);
        power->setObjectName(QString::fromUtf8("power"));
        power->setMinimumSize(QSize(55, 55));
        power->setStyleSheet(QString::fromUtf8("QPushButton#power {\n"
"	background-color: #27a9e3;\n"
"}\n"
"\n"
"QPushButton:hover { background-color: #66c011; }"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("login_bg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        power->setIcon(icon1);
        power->setIconSize(QSize(50, 50));

        horizontalLayout->addWidget(power);


        verticalLayout->addWidget(topPanel);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, 0, -1, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        logo = new QLabel(verticalLayoutWidget);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setMinimumSize(QSize(150, 150));
        logo->setStyleSheet(QString::fromUtf8("QLabel#logo {\n"
"	border: 1px solid;\n"
"}"));
        logo->setPixmap(QPixmap(QString::fromUtf8("../../../Pictures/LockheedMartin.png")));

        horizontalLayout_3->addWidget(logo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, 0);
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        loginForm = new QWidget(verticalLayoutWidget);
        loginForm->setObjectName(QString::fromUtf8("loginForm"));
        loginForm->setMinimumSize(QSize(0, 0));
        loginForm->setStyleSheet(QString::fromUtf8("QWidget#loginForm { \n"
"	background: rgba(0, 0, 0, 80);	\n"
"	border-radius: 8px;\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(loginForm);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(40, 50, 40, 40);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, -1);
        userName = new QLabel(loginForm);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setStyleSheet(QString::fromUtf8("QLabel#userName {\n"
"	color: white;\n"
"}"));
        userName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(userName);

        lineEdit = new QLineEdit(loginForm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_5->addWidget(lineEdit);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, -1);
        password = new QLabel(loginForm);
        password->setObjectName(QString::fromUtf8("password"));
        password->setAutoFillBackground(false);
        password->setStyleSheet(QString::fromUtf8("QLabel#password {\n"
"	color: white;\n"
"}"));

        horizontalLayout_6->addWidget(password);

        lineEdit_2 = new QLineEdit(loginForm);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_6->addWidget(lineEdit_2);


        verticalLayout_3->addLayout(horizontalLayout_6);

        pushButton_3 = new QPushButton(loginForm);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    background-color: #27a9e3;\n"
"    border-width: 0px;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QPushButton:hover { \n"
"	background-color: #66c011; \n"
"}"));

        verticalLayout_3->addWidget(pushButton_3);


        horizontalLayout_4->addWidget(loginForm);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        currentDateTime->setText(QApplication::translate("MainWindow", "Monday, 25-10-2015 3:14 PM", nullptr));
        restart->setText(QString());
        power->setText(QString());
        logo->setText(QString());
        userName->setText(QApplication::translate("MainWindow", "Username:", nullptr));
        password->setText(QApplication::translate("MainWindow", "Password:", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
