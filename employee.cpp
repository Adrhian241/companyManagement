#include "employee.h"
#include <QString>
#include <QListWidget>
Employee::Employee()
{

}
Employee::~Employee()
{

}
Employee::Employee(QString name,QString surname)
{
    this->name = name;
    this->surname = surname;
}
QString Employee::getName()
{
    return name;
}
QString Employee::getSurname()
{
    return surname;
}

