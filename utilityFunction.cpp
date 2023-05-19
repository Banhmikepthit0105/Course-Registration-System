#include "lib.h"

void clrscr()
{
        if (system("cls")) system("clear");
}

void stop()
{
        cin.get();
}

float float_one_point_round(float value)
{
        return ((float)((int)(value * 10))) / 10;//
}

float stf(string str)
{
        return strtof(str.c_str(), NULL);
}
