#include "editEmployeeDialog.h"
#include "ui_editEmployeeDialog.h"

EditEmployeeDialog::EditEmployeeDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialogEdit)
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

EditEmployeeDialog::~EditEmployeeDialog()
{
    delete ui;
}

void EditEmployeeDialog::setCurrentValues(const QString &name,const QString &surname,int age,const QString &position)
{
    ui->lineEditName->setText(name);
    ui->lineEditSurname->setText(surname);
    ui->spinBoxAge->setValue(age);
    int index = ui->comboBoxPosition->findText(position);
    if (index != -1) {
        ui->comboBoxPosition->setCurrentIndex(index);
    }
}


bool EditEmployeeDialog::isNameChanged()const
{
    return ui->checkBoxName->isChecked();

}

bool EditEmployeeDialog::isSurnameChanged()const
{
    return ui->checkBoxSurname->isChecked();
}

bool EditEmployeeDialog::isAgeChanged()const
{
    return ui->checkBoxAge->isChecked();
}

bool EditEmployeeDialog::isPositionChanged()const
{
    return ui->checkBoxPosition->isChecked();
}

QString EditEmployeeDialog::getNewName() const
{
    return ui->lineEditName->text();
}

QString EditEmployeeDialog::getNewSurname() const
{
    return ui->lineEditSurname->text();
}

int EditEmployeeDialog::getNewAge() const
{
    return ui->spinBoxAge->value();
}

QString EditEmployeeDialog::getNewPosition() const
{
    return ui->comboBoxPosition->currentText();
}
