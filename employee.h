#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
class Employee
{
private:
    QString name;
    QString surname;

public:
    Employee();
    Employee(QString name,QString surname);
    ~Employee();
    //void setName();
    //void setSurname();
    QString getName();
    QString getSurname();

};

#endif // EMPLOYEE_H
