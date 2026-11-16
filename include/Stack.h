#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "../include/employee.h"
#define LOG(str) std::cout<<str<<std::endl //Macors
class Stack
{

    public:
        Employee *employees;
        Stack();
        Stack(int sizeArray);
        ~Stack();
        Stack(Stack & s);
        void push(Employee e);
        int pop(Employee * e);
        void display(void);
        Stack & operator=(const Stack s);
        static int getactiveStacksCount();
    protected:


    private:
        int top;
        int sizeArray;
      
        
        // 1. Declare a static variable to count active stacks
        static int activeStacksCount;
};

#endif // STACK_H
