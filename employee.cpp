#include "employee.h"
#include <QString>
#include <QListWidget>
Employee::Employee()
{

}
Employee::~Employee()
{

}
Employee::Employee(QString name, QString surname, int age, QString position)
{
    this->name = name;
    this->surname = surname;
    this->age=age;
    this->position = position;
}
QString Employee::getName()
{
    return name;
}
QString Employee::getSurname()const
{
    return surname;
}
int Employee::getAge()const
{
    return age;
}
QString Employee::getPosition()
{
    return position;
}
