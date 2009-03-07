/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Sat Dec 13 22:27:01 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QMainWindow>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QToolBar *m_toolbar;

    void setupUi(QMainWindow *MainWindowClass)
    {
    if (MainWindowClass->objectName().isEmpty())
        MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
    MainWindowClass->resize(600, 400);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(MainWindowClass->sizePolicy().hasHeightForWidth());
    MainWindowClass->setSizePolicy(sizePolicy);
    centralWidget = new QWidget(MainWindowClass);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    MainWindowClass->setCentralWidget(centralWidget);
    m_toolbar = new QToolBar(MainWindowClass);
    m_toolbar->setObjectName(QString::fromUtf8("m_toolbar"));
    MainWindowClass->addToolBar(Qt::TopToolBarArea, m_toolbar);

    retranslateUi(MainWindowClass);

    QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
    MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", 0, QApplication::UnicodeUTF8));
    m_toolbar->setWindowTitle(QApplication::translate("MainWindowClass", "toolBar", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(MainWindowClass);
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
