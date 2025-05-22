/********************************************************************************
** Form generated from reading UI file 'gragh.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAGH_H
#define UI_GRAGH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gragh
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gragh)
    {
        if (gragh->objectName().isEmpty())
            gragh->setObjectName("gragh");
        gragh->resize(800, 600);
        centralwidget = new QWidget(gragh);
        centralwidget->setObjectName("centralwidget");
        gragh->setCentralWidget(centralwidget);
        menubar = new QMenuBar(gragh);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        gragh->setMenuBar(menubar);
        statusbar = new QStatusBar(gragh);
        statusbar->setObjectName("statusbar");
        gragh->setStatusBar(statusbar);

        retranslateUi(gragh);

        QMetaObject::connectSlotsByName(gragh);
    } // setupUi

    void retranslateUi(QMainWindow *gragh)
    {
        gragh->setWindowTitle(QCoreApplication::translate("gragh", "gragh", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gragh: public Ui_gragh {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAGH_H
