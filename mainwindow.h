#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "employee.h"
#include <QMainWindow>
#include <QlistWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAdd_clicked();
    void on_pushButtonDelete_clicked();

    //void on_pushButtonDelete_2_clicked();
    void on_pushButtonEdit_clicked();


    void filterEmployees();
    void on_lineEditSearch_returnPressed();

    void on_pushButtonSearch_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Employee> employeeList; // Lista pracowników
    void updateEmployeeList();
};
#endif // MAINWINDOW_H
