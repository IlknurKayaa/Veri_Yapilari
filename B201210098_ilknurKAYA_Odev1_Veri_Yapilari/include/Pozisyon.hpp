#ifndef POZISYON_HPP
#define POZISYON_HPP
#include <windows.h>
static class Pozisyon
{
public:
    static void gotoxy(int x, int y)
    {
        COORD a;
        a.X = x;
        a.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
    }

} Pozisyon;
#endif