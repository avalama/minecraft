#pragma once
#include "Structs.h"
class UIntArr
{
public:
    unsigned int* arraystart;
    int length;
    bool exist = false;
    int id = 0;
    UIntArr(unsigned int*, int, bool);
    UIntArr(int);
    UIntArr();
    void create(int);
    UIntArr add(UIntArr);
    ~UIntArr();
};
