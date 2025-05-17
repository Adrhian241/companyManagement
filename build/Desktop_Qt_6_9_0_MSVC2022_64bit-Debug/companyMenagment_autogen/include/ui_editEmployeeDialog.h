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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialogEdit
{
public:
    QFormLayout *formLayout;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBoxName;
    QLineEdit *lineEditName;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBoxSurname;
    QLineEdit *lineEditSurname;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBoxAge;
    QSpinBox *spinBoxAge;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBoxPosition;
    QComboBox *comboBoxPosition;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *dialogEdit)
    {
        if (dialogEdit->objectName().isEmpty())
            dialogEdit->setObjectName("dialogEdit");
        dialogEdit->resize(400, 300);
        formLayout = new QFormLayout(dialogEdit);
        formLayout->setObjectName("formLayout");
        buttonBox = new QDialogButtonBox(dialogEdit);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        formLayout->setWidget(3, QFormLayout::ItemRole::SpanningRole, buttonBox);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        checkBoxName = new QCheckBox(dialogEdit);
        checkBoxName->setObjectName("checkBoxName");

        verticalLayout->addWidget(checkBoxName);

        lineEditName = new QLineEdit(dialogEdit);
        lineEditName->setObjectName("lineEditName");

        verticalLayout->addWidget(lineEditName);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        checkBoxSurname = new QCheckBox(dialogEdit);
        checkBoxSurname->setObjectName("checkBoxSurname");

        verticalLayout_3->addWidget(checkBoxSurname);

        lineEditSurname = new QLineEdit(dialogEdit);
        lineEditSurname->setObjectName("lineEditSurname");

        verticalLayout_3->addWidget(lineEditSurname);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_5->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        checkBoxAge = new QCheckBox(dialogEdit);
        checkBoxAge->setObjectName("checkBoxAge");

        verticalLayout_4->addWidget(checkBoxAge);

        spinBoxAge = new QSpinBox(dialogEdit);
        spinBoxAge->setObjectName("spinBoxAge");

        verticalLayout_4->addWidget(spinBoxAge);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        checkBoxPosition = new QCheckBox(dialogEdit);
        checkBoxPosition->setObjectName("checkBoxPosition");

        verticalLayout_2->addWidget(checkBoxPosition);

        comboBoxPosition = new QComboBox(dialogEdit);
        comboBoxPosition->setObjectName("comboBoxPosition");

        verticalLayout_2->addWidget(comboBoxPosition);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_2);


        formLayout->setLayout(1, QFormLayout::ItemRole::SpanningRole, verticalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        formLayout->setItem(0, QFormLayout::ItemRole::SpanningRole, verticalSpacer_2);

        verticalSpacer_3 = new QSpacerItem(20, 60, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        formLayout->setItem(2, QFormLayout::ItemRole::SpanningRole, verticalSpacer_3);


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
