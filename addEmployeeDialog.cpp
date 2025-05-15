#include "addEmployeeDialog.h"
#include "ui_addEmployeeDialog.h"

AddEmployeeDialog::AddEmployeeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialogAdd)
{
    ui->setupUi(this);
    ui->comboBoxPosition->addItem("Kierownik");
    ui->comboBoxPosition->addItem("Księgowy /a");
    ui->comboBoxPosition->addItem("Pracownik IT");
    ui->comboBoxPosition->addItem("Zarząd");

    ui->spinBoxAge->setRange(18, 100);
    ui->spinBoxAge->setValue(30); // domyślna wartość
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
