/********************************************************************************
** Form generated from reading UI file 'attendanceDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTENDANCEDIALOG_H
#define UI_ATTENDANCEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_attendanceDialog
{
public:
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *attendanceDialog)
    {
        if (attendanceDialog->objectName().isEmpty())
            attendanceDialog->setObjectName("attendanceDialog");
        attendanceDialog->resize(651, 522);
        formLayout = new QFormLayout(attendanceDialog);
        formLayout->setObjectName("formLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        tableWidget = new QTableWidget(attendanceDialog);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(attendanceDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        formLayout->setLayout(0, QFormLayout::ItemRole::SpanningRole, horizontalLayout);


        retranslateUi(attendanceDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, attendanceDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, attendanceDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(attendanceDialog);
    } // setupUi

    void retranslateUi(QDialog *attendanceDialog)
    {
        attendanceDialog->setWindowTitle(QCoreApplication::translate("attendanceDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class attendanceDialog: public Ui_attendanceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTENDANCEDIALOG_H
