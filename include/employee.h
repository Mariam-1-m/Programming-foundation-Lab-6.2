#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>


struct Employee{



std::string name;
int age;
std::string department;
double salary;



Employee(std::string namep,int agep,std::string departmentp,double salaryp)
:name(namep),age(agep),department(departmentp),salary(salaryp){};

Employee():
name("unknown"),age(0),department("finance"),salary(0.0){};





};




#endif
