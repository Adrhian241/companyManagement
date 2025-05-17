#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "employee.h"
#include "addEmployeeDialog.h"
#include "editEmployeeDialog.h"
#include <QMessageBox>
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
        QMessageBox::warning(this,"Blad","Zaznacz jednego pracownika do edycji");
        return;
    }

    Employee &employee = employeeList[item];
    EditEmployeeDialog dialog(this);

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
            wasChanged = true;
        }

        if(dialog.isSurnameChanged()){
            newSurname = dialog.getNewSurname();
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
    ui->lineEditSearch->clear();
}

void MainWindow::on_lineEditSearch_returnPressed()
{
    filterEmployees();
}


void MainWindow::on_pushButtonSearch_clicked()
{
    filterEmployees();
}

