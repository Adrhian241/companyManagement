#include "addEmployeeDialog.h"
#include "ui_addEmployeeDialog.h"

AddEmployeeDialog::AddEmployeeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
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
