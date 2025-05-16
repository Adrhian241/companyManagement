/********************************************************************************
** Form generated from reading UI file 'editEmployeeDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITEMPLOYEEDIALOG_H
#define UI_EDITEMPLOYEEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialogEdit
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBoxName;
    QLineEdit *lineEditName;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBoxSurname;
    QLineEdit *lineEditSurname;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBoxAge;
    QSpinBox *spinBoxAge;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBoxPosition;
    QComboBox *comboBoxPosition;

    void setupUi(QDialog *dialogEdit)
    {
        if (dialogEdit->objectName().isEmpty())
            dialogEdit->setObjectName("dialogEdit");
        dialogEdit->resize(400, 300);
        buttonBox = new QDialogButtonBox(dialogEdit);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        widget = new QWidget(dialogEdit);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 50, 278, 52));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        checkBoxName = new QCheckBox(widget);
        checkBoxName->setObjectName("checkBoxName");

        verticalLayout->addWidget(checkBoxName);

        lineEditName = new QLineEdit(widget);
        lineEditName->setObjectName("lineEditName");

        verticalLayout->addWidget(lineEditName);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        checkBoxSurname = new QCheckBox(widget);
        checkBoxSurname->setObjectName("checkBoxSurname");

        verticalLayout_3->addWidget(checkBoxSurname);

        lineEditSurname = new QLineEdit(widget);
        lineEditSurname->setObjectName("lineEditSurname");

        verticalLayout_3->addWidget(lineEditSurname);


        horizontalLayout->addLayout(verticalLayout_3);

        widget1 = new QWidget(dialogEdit);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(60, 130, 281, 52));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        checkBoxAge = new QCheckBox(widget1);
        checkBoxAge->setObjectName("checkBoxAge");

        verticalLayout_4->addWidget(checkBoxAge);

        spinBoxAge = new QSpinBox(widget1);
        spinBoxAge->setObjectName("spinBoxAge");

        verticalLayout_4->addWidget(spinBoxAge);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        checkBoxPosition = new QCheckBox(widget1);
        checkBoxPosition->setObjectName("checkBoxPosition");

        verticalLayout_2->addWidget(checkBoxPosition);

        comboBoxPosition = new QComboBox(widget1);
        comboBoxPosition->setObjectName("comboBoxPosition");

        verticalLayout_2->addWidget(comboBoxPosition);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(dialogEdit);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, dialogEdit, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, dialogEdit, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(dialogEdit);
    } // setupUi

    void retranslateUi(QDialog *dialogEdit)
    {
        dialogEdit->setWindowTitle(QCoreApplication::translate("dialogEdit", "Dialog", nullptr));
        checkBoxName->setText(QCoreApplication::translate("dialogEdit", "Imie", nullptr));
        lineEditName->setText(QCoreApplication::translate("dialogEdit", "Podaj nowe imie", nullptr));
        checkBoxSurname->setText(QCoreApplication::translate("dialogEdit", "Nazwisko", nullptr));
        lineEditSurname->setText(QCoreApplication::translate("dialogEdit", "Podaj nowe nazwisko", nullptr));
        checkBoxAge->setText(QCoreApplication::translate("dialogEdit", "Wiek", nullptr));
        checkBoxPosition->setText(QCoreApplication::translate("dialogEdit", "Stanowisko", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogEdit: public Ui_dialogEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITEMPLOYEEDIALOG_H
