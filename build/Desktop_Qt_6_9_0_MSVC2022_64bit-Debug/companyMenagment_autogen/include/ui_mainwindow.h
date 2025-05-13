/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QListWidget *listWidget;
    QLineEdit *lineEditName;
    QLineEdit *lineEditSurname;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButtonAdd = new QPushButton(centralwidget);
        pushButtonAdd->setObjectName("pushButtonAdd");
        pushButtonAdd->setGeometry(QRect(160, 210, 83, 29));
        pushButtonDelete = new QPushButton(centralwidget);
        pushButtonDelete->setObjectName("pushButtonDelete");
        pushButtonDelete->setGeometry(QRect(160, 270, 83, 29));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(310, 170, 256, 192));
        lineEditName = new QLineEdit(centralwidget);
        lineEditName->setObjectName("lineEditName");
        lineEditName->setGeometry(QRect(310, 30, 113, 28));
        lineEditSurname = new QLineEdit(centralwidget);
        lineEditSurname->setObjectName("lineEditSurname");
        lineEditSurname->setGeometry(QRect(310, 70, 113, 28));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
