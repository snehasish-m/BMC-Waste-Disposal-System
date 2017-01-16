#include<windows.h>
#include<iostream>
using namespace std;
namespace cursor
{
    void move_pointer()
    {
        //initialize objects for cursor manipulation
        HANDLE hStdout;
        COORD destCoord;
        hStdout = GetStdHandle(STD_OUTPUT_HANDLE);   //referred  from stackoverflow.com

        //position cursor at start of window
        destCoord.X = 40;
        destCoord.Y = 10;
        SetConsoleCursorPosition(hStdout,destCoord);
    }
}
