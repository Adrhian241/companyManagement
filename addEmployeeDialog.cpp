#include "addEmployeeDialog.h"
#include "ui_addEmployeeDialog.h"
#include <QMessageBox>

AddEmployeeDialog::AddEmployeeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialogAdd)
{
    ui->setupUi(this);
    ui->comboBoxPosition->addItem("Prezes_zarządu");
    ui->comboBoxPosition->addItem("Menedżer");
    ui->comboBoxPosition->addItem("Księgowy");
    ui->comboBoxPosition->addItem("Programista");
    ui->comboBoxPosition->addItem("Logistyk");
    ui->comboBoxPosition->addItem("Analityk_finansowy");
    ui->comboBoxPosition->addItem("Inżynier_danych");
    ui->comboBoxPosition->addItem("Administrator_sieci");

    ui->spinBoxAge->setRange(18, 100);
    ui->spinBoxAge->setValue(30); // domyślna wartość

    QRegularExpression regex("^[A-Za-zżźćńółęąśŻŹĆĄŚĘŁÓŃ\\s-]{1,50}$");
    auto *validator = new QRegularExpressionValidator(regex, this);
    ui->lineEditName->setValidator(validator);
    ui->lineEditSurname->setValidator(validator);

}

AddEmployeeDialog::~AddEmployeeDialog()
{
    delete ui;
}

QString AddEmployeeDialog::getName() const
{
    return ui->lineEditName->text();
}

QString AddEmployeeDialog::getSurname() const
{
    return ui->lineEditSurname->text();
}
int AddEmployeeDialog::getAge() const
{
    return ui->spinBoxAge->value();
}
QString AddEmployeeDialog::getPosition()const
{
    return ui->comboBoxPosition->currentText();
}



