#include "../include/employee.h"

Employee::Employee(std::string name,int age,std::string department,double salary)
{
    this->name=name;
    this->age=age;
    this->department=department;
    this->salary=salary;

}

Employee::Employee(){
    this->name="unknown";
    this->age=20;
    this->department="Finance";
    this->salary=20000;
}