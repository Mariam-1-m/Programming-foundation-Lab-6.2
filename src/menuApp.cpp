#include <iostream>
#include "../include/menu.h"
#include "../include/colors.h"
#include "../include/arrowGet.h"
#include "../include/menuApp.h"
#include "../include/Stack.h"
#include <thread>
#include <chrono>




#include <cstdio>    
#ifndef _WIN32
#include <unistd.h>
#endif




menuApp::menuApp(){


empCount=0;
currentIndex=0;
userColor="yellow";

 options[0]= "New Screen";
 options[1]= "Display Screen" ;
 options[2]="Exit" ;
 
    capacity=20;
    s=new Stack(capacity);
   x_axis=10;
   y_axis=10;
   menuSize=3;
 
}

void menuApp::displayMenu(){
std::cout<<"\033[2J\033[H"<<std::flush;
for(int i=0;i<menuSize;i++){
    goToXY(x_axis, y_axis + i);
if (i== currentIndex){
    std::cout << "\033[1;37m";
    std::cout<<setColor(userColor) <<"→ "<<options[i] <<Color::RESET<<"\n" ;
}else{
    std::cout <<"  "<<options[i]<<"\n" ;

}

}
}


void menuApp::resizeCapacity(){
Employee e;
int newCapacity=capacity*2;
Stack * temp=new Stack(newCapacity);
for(int i=0 ;i<capacity;i++){
    s->pop(&e);
    temp->push(e);
    
}
delete [] s;
s=temp;
capacity=newCapacity;
}

void menuApp::observeUserKeys(){

    std::printf("Press the arrow keys to test the program (press 'q' to quit):\n");
    char byte1='q';
    char byte2='q';
    char byte3='q';

   
    do{
         std::cout<<"\033[2J\033[H"<<std::flush;
      
        displayMenu();
     

        byte1= getch_linux();
      
        if (byte1 == '\033') {

            byte2=getch_linux();
            byte3=getch_linux();
         
            
            switch (byte3) {
                case 'A'://up
                
                      currentIndex=(currentIndex-1+menuSize)%menuSize;
                    
                    break;

                case 'B': //down
                 currentIndex=(currentIndex+1)%menuSize;
                    break;

                case 'C':
                    std::printf("→ Right Arrow\n");
                    break;

                case 'D':
                    std::printf("← Left Arrow\n");
                    break;
                case 'H':
                    currentIndex=0;
                    break;
                case 'F':
                   currentIndex=3;
                    break;
                
            
            }
        }else if(byte1=='\n' || byte1=='\r'){
    
            switch (currentIndex){
                case 0:
                addNewEmployee();
                break;
                case 1:
                displayAllEmployees();
                break;
                case 2:
                std::cout<<"\033[2J\033[H"<<std::flush;
                std::cout<<"Quitted!";
                byte1='q';
                return;
              
               

            }
        }

        std::cout<<"================================="<<std::endl;
    }while(byte1 != 'q' && byte1 != 'Q');        // Exit the program if the user presses Q or q
    // Exit the program successfully
 std::cout<<"\033[2J\033[H"<<std::flush;

}

void menuApp::addNewEmployee(){
std::string name;
int age;
std::string department;
double salary;
char cont;
 std::cout<<"\033[2J\033[H"<<std::flush;
std::cout<<"=========================== ADD EMPLOYEE SCREEN ============================\n\n";

do{

if(empCount>=capacity){
  resizeCapacity();
}
std::cout<<"Enter employee name : \n";
std::cin>>name;
std::cin.ignore(10000,'\n');

std::cout<<"Enter employee age : \n";
std::cin>>age;
if(age<=0){
    std::cout<<"Try again with a valid age!"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return;
}
std::cin.ignore(10000,'\n');


std::cout<<"Enter employee department : \n";
std::cin>>department;
std::cin.ignore(10000,'\n');

std::cout<<"Enter employee salary: \n";
std::cin>>salary;
if(salary<=0){
   std::cout<<"Try again with a valid salary!"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return;
}
std::cin.ignore(10000,'\n');

s->push(Employee(name,age,department,salary));

empCount++;
std::cout<<empCount;
std::cout<<"Do you want to continue? y/n\n";
std::cin>>cont;
std::cin.ignore(10000,'\n');


}while(cont=='y' || cont=='Y');
std::cin.clear();
}

void menuApp::displayAllEmployees(){
    std::cout<<"\033[2J\033[H"<<std::flush;
    std::cout<<"=========================== DISPLAY OUR EMPLOYEES ==========================\n";
    for(int i=0;i<empCount;i++){
    std::cout<<"\n"<<"Employee : "<<i+1 <<" \n";
    std::cout<<"Name : "<<s->employees[i].name<<"\n";
    std::cout<<"Age : "<<s->employees[i].age<<"\n";
    std::cout<<"Department : "<<s->employees[i].department<<"\n";
    std::cout<<"Salary : "<<s->employees[i].salary<<"\n";
    std::cout<<"========================";
    }
    std::cin.ignore();
    std::cin.get();
}





menuApp::~menuApp(){
    delete [] s->employees;
}