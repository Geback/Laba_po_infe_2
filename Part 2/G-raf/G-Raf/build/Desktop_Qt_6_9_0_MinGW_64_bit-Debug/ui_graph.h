/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_graph
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *graph)
    {
        if (graph->objectName().isEmpty())
            graph->setObjectName("graph");
        graph->resize(800, 600);
        centralwidget = new QWidget(graph);
        centralwidget->setObjectName("centralwidget");
        graph->setCentralWidget(centralwidget);
        menubar = new QMenuBar(graph);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        graph->setMenuBar(menubar);
        statusbar = new QStatusBar(graph);
        statusbar->setObjectName("statusbar");
        graph->setStatusBar(statusbar);

        retranslateUi(graph);

        QMetaObject::connectSlotsByName(graph);
    } // setupUi

    void retranslateUi(QMainWindow *graph)
    {
        graph->setWindowTitle(QCoreApplication::translate("graph", "graph", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graph: public Ui_graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
