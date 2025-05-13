#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "employee.h"
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
    QString name = ui->lineEditName->text();
    QString surname = ui->lineEditSurname->text();

    if(name.isEmpty()|| surname.isEmpty())
    {
        QMessageBox::warning(this, "Błąd", "Imię i nazwisko nie mogą być puste.");
        return;
    }
    Employee newEmployee(name, surname);

    // Dodawanie pracownika do listy
    employeeList.push_back(newEmployee);

    // Aktualizacja QListWidget
    updateEmployeeList();

    // Czyszczenie pól tekstowych
    ui->lineEditName->clear();
    ui->lineEditSurname->clear();
}
void MainWindow::updateEmployeeList()
{
    ui->listWidget->clear(); // Czyścimy QListWidget

    // Iterujemy po liście pracowników i dodajemy ich do QListWidget
    for (size_t i = 0; i < employeeList.size(); ++i) {
        Employee employee = employeeList[i]; // Tworzymy kopię elementu
        QString displayText = employee.getName() + " " + employee.getSurname();
        ui->listWidget->addItem(displayText);
    }
}

