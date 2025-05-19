#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
class Employee
{
private:
    QString name;
    QString surname;
    int age;
    QString position;

public:
    Employee();
    Employee(QString name,QString surname,int age,QString position);
    ~Employee();
    QString getName() const;
    QString getSurname() const;
    int getAge() const;
    QString getPosition();
    QString toFileString()const;
    void fromFileString(const QString &line);

};

#endif // EMPLOYEE_H
