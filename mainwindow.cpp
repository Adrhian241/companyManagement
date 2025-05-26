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
    dialog.show();
    if(dialog.exec() == QDialog::Accepted){
    QString name = dialog.getName();
    QString surname = dialog.getSurname();

    //qDebug() << "Długość imienia:" << name.length();
    //qDebug() << "Długość imienia:" << surname.length();

        try {
        Validator::validateName(name);
        Validator::validateSurname(surname);
        } catch (const std::exception& exp) {
            QMessageBox::warning(this,"Blad walidacji",exp.what());
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

    // Dodawanie pracownika do listy
    employeeList.push_back(newEmployee);
    workHours.push_back({0, 0, 0, 0, 0, 0, 0});
    hourlyRate.push_back(0.0);

    // Aktualizacja QListWidget
    updateEmployeeList();
    }
    // Czyszczenie pól tekstowych
    //ui->lineEditName->clear();
    //ui->lineEditSurname->clear();
}
void MainWindow::updateEmployeeList()
{
    ui->listWidget->clear(); // Czyścimy QListWidget

    // Iterujemy po liście pracowników i dodajemy ich do QListWidget
    for (size_t i = 0; i < employeeList.size(); ++i) {
        Employee employee = employeeList[i]; // Tworzymy kopię elementu
        QString displayText = employee.getName() + "     " + employee.getSurname() + "     " + QString::number(employee.getAge()) + "     " + employee.getPosition();

        //QListWidgetItem *item = new QListWidgetItem(displayText);
        //item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter); // Przyrównanie elementu do lewej i środka
        //item->setSizeHint(QSize(ui->listWidget->width(), item->sizeHint().height())); //Wymuszenie do rozciągnięcia itemu na szerokość listy

        ui->listWidget->addItem(displayText);
    }

}
void MainWindow::on_pushButtonDelete_clicked(){

    QListWidgetItem *item = ui->listWidget->currentItem();
    if (item) {
        // Znalezienie indeksu zaznaczonego elementu w QListWidget
        int rowIndex = ui->listWidget->row(item);

        // Usunięcie pracownika z listy employeeList na podstawie indeksu
        employeeList.erase(employeeList.begin() + rowIndex);
        workHours.erase(workHours.begin() + rowIndex);
        hourlyRate.erase(hourlyRate.begin() + rowIndex);

        // Usuwamy element z QListWidget
        delete item;

        // Zaktualizowanie widoku w QListWidget
        updateEmployeeList();
    } else {
        // Jeśli nie zaznaczono elementu, wyświetl komunikat
        QMessageBox::warning(this, "Brak zaznaczenia", "Proszę zaznaczyć element do usunięcia.");
    }
}

void MainWindow::on_pushButtonEdit_clicked()
{
    int item = ui->listWidget->currentRow();

    //Sprawdzenie czy wybrano pracownika
    if(item < 0 || item >= static_cast<int>(employeeList.size())){
        QMessageBox::warning(this,"Blad","Zaznacz pracownika do edycji");
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
        //Przypisanie aktualnych wartości do zmiennych

        bool wasChanged = false;//Flaga do sprawdzenia czy wprowadzono zmiany

        if(dialog.isNameChanged()){ //Sprawdzenie czy checkbox jest zaznaczony
            newName = dialog.getNewName();
            try {
                Validator::validateName(newName);
            } catch (const std::exception& exp) {
                QMessageBox::warning(this,"Blad walidacji",exp.what());
                return;
            }
            wasChanged = true;
        }

        if(dialog.isSurnameChanged()){
            newSurname = dialog.getNewSurname();
            try {
                Validator::validateSurname(newSurname);
            } catch (const std::exception& exp) {
                QMessageBox::warning(this,"Blad walidacji",exp.what());
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

        //Przypisanie zmienionych wartości dla wybranego wcześniej pracownika
        employee = Employee(newName,newSurname,newAge,newPosition);
        updateEmployeeList();

        if(wasChanged){ //Sprawdzenie czy wprowadzono zmiany
            QMessageBox::warning(this,"Komunikat","Zmiany zostały wprowadzone pomyślnie");
        }else{
            QMessageBox::warning(this,"Komunikat","Nie wprowadzono zmian");
        }
    }

}


void MainWindow::filterEmployees()
{
    QString searchText = ui->lineEditSearch->text();
    try {
        Validator::validateSearchText(searchText);
    } catch (const std::exception& exp) {
        QMessageBox::warning(this,"Blad walidacji",exp.what());
        ui->lineEditSearch->clear();
        return;
    }
    // Sprawdzenie czy wyszukiwany tekst spełnia wymagania
    // Jeśli nie spełnia to czyszczony jest tekst w pasku wyszukiwania
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
//jest ustawione że przy wczytaniu danych, lista się nie czyści z poprzednich wpisanych pracowników
//ale mozna to latwo zmienic tylko nie wiedziałem jak to chcemy zrobic
//można dodać ew bledy jak ktos wpisze stringa jako wiek czy cos
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

