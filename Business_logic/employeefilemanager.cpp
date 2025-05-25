#include "employeefilemanager.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

bool EmployeeFileManager::saveEmployeesToFile(const std::vector<Employee>& employees, const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return false;
    }

    QTextStream out(&file);
    for (const Employee &employee : employees)
    {
        out << employee.toFileString() << "\n";
    }
    file.close();
    return true;
}

bool EmployeeFileManager::loadEmployeesFromFile(std::vector<Employee>& employees, const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        Employee employee;
        employee.fromFileString(line);
        employees.push_back(employee);
    }
    file.close();
    return true;
}
