#pragma once
#include"Structs.h"
/*float *= new array first member place
int= length of array in SLOTS
bool=is array dynamic and new for true and if its static for false*/
class floatarray
{
public:
    float* arraystart;
    int length;
    bool exist = false;
    int id = 0;
    floatarray(float*, int, bool);
    floatarray(int);
    floatarray();
    void create(int);
    floatarray add(floatarray);
    ~floatarray();
};
int getdes();
