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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_dialogAdd
{
public:
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
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
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialogAdd)
    {
        if (dialogAdd->objectName().isEmpty())
            dialogAdd->setObjectName("dialogAdd");
        dialogAdd->resize(400, 300);
        formLayout = new QFormLayout(dialogAdd);
        formLayout->setObjectName("formLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_5->addItem(verticalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(dialogAdd);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(dialogAdd);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(dialogAdd);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(dialogAdd);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEditSurname = new QLineEdit(dialogAdd);
        lineEditSurname->setObjectName("lineEditSurname");

        verticalLayout->addWidget(lineEditSurname);

        lineEditName = new QLineEdit(dialogAdd);
        lineEditName->setObjectName("lineEditName");

        verticalLayout->addWidget(lineEditName);

        spinBoxAge = new QSpinBox(dialogAdd);
        spinBoxAge->setObjectName("spinBoxAge");

        verticalLayout->addWidget(spinBoxAge);

        comboBoxPosition = new QComboBox(dialogAdd);
        comboBoxPosition->setObjectName("comboBoxPosition");

        verticalLayout->addWidget(comboBoxPosition);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_2 = new QSpacerItem(20, 80, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_3->addItem(verticalSpacer_2);

        buttonBox = new QDialogButtonBox(dialogAdd);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout_3->addWidget(buttonBox);


        verticalLayout_4->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(verticalLayout_4);


        formLayout->setLayout(0, QFormLayout::ItemRole::SpanningRole, verticalLayout_5);


        retranslateUi(dialogAdd);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, dialogAdd, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, dialogAdd, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(dialogAdd);
    } // setupUi

    void retranslateUi(QDialog *dialogAdd)
    {
        dialogAdd->setWindowTitle(QCoreApplication::translate("dialogAdd", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("dialogAdd", "Imi\304\231:", nullptr));
        label_2->setText(QCoreApplication::translate("dialogAdd", "Nazwisko", nullptr));
        label_3->setText(QCoreApplication::translate("dialogAdd", "Wiek:", nullptr));
        label_4->setText(QCoreApplication::translate("dialogAdd", "Stanowisko:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialogAdd: public Ui_dialogAdd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEMPLOYEEDIALOG_H
