#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include "EmployeeType.h"

class Employee
{
private:
    std::string _name;
    EmployeeType _type;
    float _salary;

public:

Employee(std::string name, EmployeeType type, float salary);

Employee()=default;
~Employee()=default;

Employee(const Employee&)=delete;
Employee(Employee&&)=delete;

Employee &operator=(const Employee&)=delete;
Employee &operator=(Employee&&)=delete;

EmployeeType type() const { return _type; }

std::string name() const { return _name; }

float salary() const { return _salary; }

};

#endif // EMPLOYEE_H
