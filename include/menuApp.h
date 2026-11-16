#ifndef MENUAPP_H
#define MENUAPP_H
#include "../include/menu.h"
#include "../include/Stack.h"
#include "../include/employee.h"
#include <iostream>


#include <cstdio>    
#ifndef _WIN32
#include <unistd.h>
#endif



struct menuApp
{
private:
  int currentIndex;
  const char* options[3] ;
  std::string_view userColor;
  int x_axis;
  int y_axis;
  Stack * s;
  int capacity;
  int empCount;
  int menuSize;
 

public:
menuApp();
~menuApp();
void setCurrentIndex(int currentIndex);
int getCurrentIndex();
void resizeCapacity();



void getCurrentCoordinates(int &x_axis,int &y_axis);

void observeUserKeys( );
void displayMenu();

void addNewEmployee();

void displayAllEmployees();

};

#endif