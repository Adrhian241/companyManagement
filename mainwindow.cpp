#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "employee.h"
#include "addEmployeeDialog.h"
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
        QString displayText = employee.getName() + " " + employee.getSurname() + " " + QString::number(employee.getAge()) + " " + employee.getPosition();
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



