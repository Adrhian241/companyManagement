#ifndef ATTENDANCEDIALOG_H
#define ATTENDANCEDIALOG_H

#include <QDialog>
#include <QTableWidget>
#include <QMap>
#include "employee.h"

namespace Ui {
class attendanceDialog;
}

class attendanceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit attendanceDialog(const std::vector<Employee>& employees,std::vector<std::array<int, 7>>& workHours,std::vector<double>& hourlyRate ,QWidget *parent = nullptr);
    ~attendanceDialog();
    void updateSalary(int row);

private:
    Ui::attendanceDialog *ui;
    std::vector<std::array<int, 7>>& workHours;
    std::vector<double>& hourlyRate;
    //std::vector<std::array<int, 7>>& workHoursCopy;
    //std::vector<double>& hourlyRateCopy;
    void setupTable(const std::vector<Employee>& employees);
    QString getEmployee(const Employee& emp) const;
};

#endif // ATTENDANCEDIALOG_H
