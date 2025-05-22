/********************************************************************************
** Form generated from reading UI file 'maintree.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINTREE_H
#define UI_MAINTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainTree
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainTree)
    {
        if (MainTree->objectName().isEmpty())
            MainTree->setObjectName("MainTree");
        MainTree->resize(800, 600);
        centralwidget = new QWidget(MainTree);
        centralwidget->setObjectName("centralwidget");
        MainTree->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainTree);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainTree->setMenuBar(menubar);
        statusbar = new QStatusBar(MainTree);
        statusbar->setObjectName("statusbar");
        MainTree->setStatusBar(statusbar);

        retranslateUi(MainTree);

        QMetaObject::connectSlotsByName(MainTree);
    } // setupUi

    void retranslateUi(QMainWindow *MainTree)
    {
        MainTree->setWindowTitle(QCoreApplication::translate("MainTree", "MainTree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainTree: public Ui_MainTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINTREE_H
