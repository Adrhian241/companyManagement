#ifndef EMPLOYEEFILEMANAGER_H
#define EMPLOYEEFILEMANAGER_H

#include "employee.h"
#include <QString>
#include <vector>

class EmployeeFileManager
{
public:
    static bool saveEmployeesToFile(const std::vector<Employee>& employees, const QString& filePath);
    static bool loadEmployeesFromFile(std::vector<Employee>& employees, const QString& filePath);
};

#endif
