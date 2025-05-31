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

QString Employee::getName() const
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

QString Employee::toFileString()const
{
    return name + " " + surname + " " + QString::number(age)+ " " + position;
}

void Employee::fromFileString(const QString &line)  //w  pliku dane musza byc oddzielone spacją i być jednowyrazowe
{
    QStringList parts = line.split(" ");
    if(parts.size()==4)
    {
        name=parts[0];
        surname=parts[1];
        age=parts[2].toInt();
        position=parts[3];
    }
}
