#pragma once
#include"IncludesAndLibraries.h"
struct DPOINT
{
    double x;
    double y;
};
struct position
{
    float x;
    float y;
    float z;
};
void* __cdecl ncalloc(
    _In_ _CRT_GUARDOVERFLOW size_t _Count,
    _In_ _CRT_GUARDOVERFLOW size_t _Size
);
int getcounter();
