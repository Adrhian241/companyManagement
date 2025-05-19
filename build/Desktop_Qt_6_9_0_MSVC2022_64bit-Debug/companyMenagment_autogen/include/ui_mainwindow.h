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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QPushButton *pushButtonEdit;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButtonSave;
    QPushButton *pushButtonLoad;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLineEdit *lineEditSearch;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonSearch;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_5;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_7);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButtonAdd = new QPushButton(centralwidget);
        pushButtonAdd->setObjectName("pushButtonAdd");

        verticalLayout->addWidget(pushButtonAdd);

        pushButtonDelete = new QPushButton(centralwidget);
        pushButtonDelete->setObjectName("pushButtonDelete");

        verticalLayout->addWidget(pushButtonDelete);

        pushButtonEdit = new QPushButton(centralwidget);
        pushButtonEdit->setObjectName("pushButtonEdit");

        verticalLayout->addWidget(pushButtonEdit);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pushButtonSave = new QPushButton(centralwidget);
        pushButtonSave->setObjectName("pushButtonSave");

        verticalLayout->addWidget(pushButtonSave);

        pushButtonLoad = new QPushButton(centralwidget);
        pushButtonLoad->setObjectName("pushButtonLoad");

        verticalLayout->addWidget(pushButtonLoad);

        verticalLayout->setStretch(0, 10);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 8);

        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setVerticalSpacing(10);
        lineEditSearch = new QLineEdit(centralwidget);
        lineEditSearch->setObjectName("lineEditSearch");

        formLayout->setWidget(0, QFormLayout::ItemRole::SpanningRole, lineEditSearch);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButtonClear = new QPushButton(centralwidget);
        pushButtonClear->setObjectName("pushButtonClear");

        horizontalLayout->addWidget(pushButtonClear);

        pushButtonSearch = new QPushButton(centralwidget);
        pushButtonSearch->setObjectName("pushButtonSearch");

        horizontalLayout->addWidget(pushButtonSearch);


        formLayout->setLayout(1, QFormLayout::ItemRole::SpanningRole, horizontalLayout);


        verticalLayout_3->addLayout(formLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        verticalLayout_2->addWidget(listWidget);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 9);

        verticalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(2, 4);

        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_6);

        verticalLayout_4->setStretch(0, 3);
        verticalLayout_4->setStretch(1, 10);
        verticalLayout_4->setStretch(2, 5);

        horizontalLayout_4->addLayout(verticalLayout_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 8);
        horizontalLayout_4->setStretch(2, 2);

        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("MainWindow", "Dodaj pracownika", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("MainWindow", "Usu\305\204 pracownika", nullptr));
        pushButtonEdit->setText(QCoreApplication::translate("MainWindow", "Edycja", nullptr));
        pushButtonSave->setText(QCoreApplication::translate("MainWindow", "Zapisz do pliku", nullptr));
        pushButtonLoad->setText(QCoreApplication::translate("MainWindow", "Wczytaj z pliku", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("MainWindow", "Wyczy\305\233\304\207 filtr ", nullptr));
        pushButtonSearch->setText(QCoreApplication::translate("MainWindow", "Szukaj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
