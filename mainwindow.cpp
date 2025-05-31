#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Business_logic/employee.h"
#include "Business_logic/employeefilemanager.h"
#include "addEmployeeDialog.h"
#include "editEmployeeDialog.h"
#include "attendanceDialog.h"
#include "Business_logic/validator.h"
#include "Business_logic/exceptionsProject.h"
#include <QMessageBox>
#include <QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAdd_clicked()
{
    AddEmployeeDialog dialog(this);
    if(dialog.exec() == QDialog::Accepted){
    QString name = dialog.getName();
    QString surname = dialog.getSurname();

        try {
        Validator::validateName(name);
        Validator::validateSurname(surname);
        } catch (const std::exception& exp) {
            QMessageBox::warning(this,"Nie poprawna długość",exp.what());
            return;
        }
    QString position = dialog.getPosition();
    int age = dialog.getAge();
    if(name.isEmpty()|| surname.isEmpty())
    {
        QMessageBox::warning(this, "Błąd", "Imię i nazwisko nie mogą być puste.");
        return;
    }

    Employee newEmployee(name, surname,age,position);

    employeeList.push_back(newEmployee);
    workHours.push_back({0, 0, 0, 0, 0, 0, 0});
    hourlyRate.push_back(0.0);

    updateEmployeeList();
    QMessageBox::information(this,"Sukces","Pomyslnie dodano pracownika");
    }
    else{
    QMessageBox::information(this,"Anulowano","Nie dodano pracownika");
    }
}

void MainWindow::updateEmployeeList()
{
    ui->listWidget->clear();

    for (size_t i = 0; i < employeeList.size(); ++i) {
        Employee employee = employeeList[i];
        QString displayText = employee.getName() + "     " + employee.getSurname() + "     " + QString::number(employee.getAge()) + "     " + employee.getPosition();

        ui->listWidget->addItem(displayText);
    }

}

void MainWindow::on_pushButtonDelete_clicked(){

    QListWidgetItem *item = ui->listWidget->currentItem();
    if (item) {
        int rowIndex = ui->listWidget->row(item);

        employeeList.erase(employeeList.begin() + rowIndex);
        workHours.erase(workHours.begin() + rowIndex);
        hourlyRate.erase(hourlyRate.begin() + rowIndex);

        delete item;

        updateEmployeeList();
        QMessageBox::information(this, "Sukces", "Usunięto pracownika");
    } else {
        QMessageBox::warning(this, "Brak zaznaczenia", "Proszę zaznaczyć element do usunięcia.");
    }
}

void MainWindow::on_pushButtonEdit_clicked()
{
    int item = ui->listWidget->currentRow();

    if(item < 0 || item >= static_cast<int>(employeeList.size())){
        QMessageBox::warning(this,"Nie wybrano pracownika","Zaznacz pracownika do edycji");
        return;
    }

    Employee &employee = employeeList[item];
    EditEmployeeDialog dialog(this);
    dialog.show();
    dialog.setCurrentValues(employee.getName(),employee.getSurname(),employee.getAge(),employee.getPosition());

    if(dialog.exec()== QDialog::Accepted){
        QString newName = employee.getName();
        QString newSurname = employee.getSurname();
        int newAge = employee.getAge();
        QString newPosition = employee.getPosition();

        bool wasChanged = false;

        if(dialog.isNameChanged()){
            newName = dialog.getNewName();
            try {
                Validator::validateName(newName);
            } catch (const std::exception& exp) {
                QMessageBox::warning(this,"Nie poprawna długość",exp.what());
                return;
            }
            wasChanged = true;
        }

        if(dialog.isSurnameChanged()){
            newSurname = dialog.getNewSurname();
            try {
                Validator::validateSurname(newSurname);
            } catch (const std::exception& exp) {
                QMessageBox::warning(this,"Nie poprawna długość",exp.what());
                return;
            }
            wasChanged = true;

        }

        if(dialog.isAgeChanged()){
            newAge = dialog.getNewAge();
             wasChanged = true;
        }

        if(dialog.isPositionChanged()){
            newPosition = dialog.getNewPosition();
             wasChanged = true;
        }

        employee = Employee(newName,newSurname,newAge,newPosition);
        updateEmployeeList();

        if(wasChanged){
            QMessageBox::information(this,"Sukces","Zmiany zostały wprowadzone pomyślnie");
        }else{
            QMessageBox::information(this,"Anulowano","Nie wprowadzono zmian");
        }
    }
    else{
        QMessageBox::information(this,"Anulowano","Nie wprowadzono zmian");
    }

}

void MainWindow::filterEmployees()
{
    QString searchText = ui->lineEditSearch->text();
    try {
        Validator::validateSearchText(searchText);
    } catch (const std::exception& exp) {
        QMessageBox::warning(this,"Nie poprawna długość",exp.what());
        ui->lineEditSearch->clear();
        return;
    }

    bool foundAny = false;

    for (int i = 0; i < ui->listWidget->count(); ++i) {
        QListWidgetItem *item = ui->listWidget->item(i);
        bool match = item->text().contains(searchText, Qt::CaseInsensitive);
        item->setHidden(!match);
        if (match) foundAny = true;
    }

    if (!foundAny) {
        QMessageBox::information(this, "Brak wyników", "Nie znaleziono pracownika o wpisanych danych.");
        for (int i = 0; i < ui->listWidget->count(); ++i) {
            ui->listWidget->item(i)->setHidden(false);
        }
    }

}

void MainWindow::on_lineEditSearch_returnPressed()
{
    filterEmployees();
}

void MainWindow::on_pushButtonSearch_clicked()
{
    filterEmployees();
}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->lineEditSearch->clear();
    for (int i = 0; i < ui->listWidget->count(); ++i)
    {
        ui->listWidget->item(i)->setHidden(false);
    }
}

void MainWindow::on_pushButtonLoad_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Wczytaj listę pracowników", "", "Pliki tekstowe (*.txt)");
    if (filePath.isEmpty()) return;

    if (EmployeeFileManager::loadEmployeesFromFile(employeeList, filePath))
    {
        updateEmployeeList();
        QMessageBox::information(this, "Sukces", "Dane zostały wczytane!");
    }
    else
    {
        QMessageBox::warning(this, "Błąd", "Nie można wczytać pliku!");
    }
}

void MainWindow::on_pushButtonSave_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Zapisz listę pracowników", "", "Pliki tekstowe (*.txt)");
    if (filePath.isEmpty()) return;

    if (EmployeeFileManager::saveEmployeesToFile(employeeList, filePath))
    {
        QMessageBox::information(this, "Sukces", "Dane zostały zapisane!");
    }
    else
    {
        QMessageBox::warning(this, "Błąd", "Nie można zapisać do pliku!");
    }
}

void MainWindow::on_pushButtonAttendance_clicked()
{
    if(workHours.size()!= employeeList.size()){
        workHours.resize(employeeList.size(),{0,0,0,0,0,0,0});
    }
    if(hourlyRate.size()!=employeeList.size()){
        hourlyRate.resize(employeeList.size(),0.0);
    }

    attendanceDialog dialog(employeeList,workHours,hourlyRate,this);
    dialog.exec();

}

