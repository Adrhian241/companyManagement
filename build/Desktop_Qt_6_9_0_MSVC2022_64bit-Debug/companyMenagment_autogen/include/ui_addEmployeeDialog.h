/********************************************************************************
** Form generated from reading UI file 'addEmployeeDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEMPLOYEEDIALOG_H
#define UI_ADDEMPLOYEEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditSurname;
    QLineEdit *lineEditName;
    QSpinBox *spinBoxAge;
    QComboBox *comboBoxPosition;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        widget = new QWidget(Dialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(120, 50, 184, 122));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(widget);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEditSurname = new QLineEdit(widget);
        lineEditSurname->setObjectName("lineEditSurname");

        verticalLayout->addWidget(lineEditSurname);

        lineEditName = new QLineEdit(widget);
        lineEditName->setObjectName("lineEditName");

        verticalLayout->addWidget(lineEditName);

        spinBoxAge = new QSpinBox(widget);
        spinBoxAge->setObjectName("spinBoxAge");

        verticalLayout->addWidget(spinBoxAge);

        comboBoxPosition = new QComboBox(widget);
        comboBoxPosition->setObjectName("comboBoxPosition");

        verticalLayout->addWidget(comboBoxPosition);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Imi\304\231:", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Nazwisko", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "Wiek:", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "Stanowisko:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEMPLOYEEDIALOG_H
