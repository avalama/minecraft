#include"Structs.h"
int counter = 0;

void* __cdecl ncalloc(
    _In_ _CRT_GUARDOVERFLOW size_t _Count,
    _In_ _CRT_GUARDOVERFLOW size_t _Size
)
{
    counter++;
    return calloc(_Count, _Size);
}
int getcounter()
{
    return counter;
}