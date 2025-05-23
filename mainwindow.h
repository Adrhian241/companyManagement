#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Business_logic/employee.h"
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
    void on_pushButtonEdit_clicked();
    void filterEmployees();
    void on_lineEditSearch_returnPressed();
    void on_pushButtonSearch_clicked();

    void on_pushButtonLoad_clicked();

    void on_pushButtonSave_clicked();



    void on_pushButtonClear_clicked();

    void on_pushButtonAttendance_clicked();

private:

    Ui::MainWindow *ui;
    std::vector<Employee> employeeList; // Lista pracowników
    void updateEmployeeList();
    std::vector<std::array<int, 7>> workHours;
    std::vector<double> hourlyRate;

};
#endif // MAINWINDOW_H
