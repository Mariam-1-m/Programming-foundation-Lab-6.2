#include <iostream>
#include "../include/menu.h"
#include "../include/colors.h"



#ifndef _WIN32
#include <unistd.h>
#endif

using namespace std;


void goToXY(int x,int y){
#ifdef _WIN32
   
    Handle hConsole =GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position ={(SHORT)x,(SHORT)y};
    SETConsoleCursorPosition(hConsole,position);
    #else
    cout << "\033[" << y + 1 << ";" << x + 1 << "H"<<std::flush;
    #endif
}



std::string_view setColor(std::string_view color){

if(Color::toOneColorName(color).empty()){
    return "Enter a valid color , please!";
}

return Color::toOneColorName(color);

}







