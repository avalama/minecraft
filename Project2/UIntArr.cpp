#include"UIntArr.h"
UIntArr::UIntArr(unsigned int* arraystart, int length, bool IsStatic) :arraystart(arraystart), length(length), exist(!IsStatic)
{
	if (!IsStatic)
	{
		arraystart = (unsigned int*)(ncalloc(length, sizeof(unsigned int)));
	}
}	//creates and allocates a new array
UIntArr::UIntArr(int length) :length(length), exist(true)
{
	arraystart = (unsigned int*)(ncalloc(length, sizeof(unsigned int)));
}
UIntArr::UIntArr()
{
}
UIntArr::~UIntArr()
{
	if (exist)
	{
		exist = false;
		free(arraystart);
		arraystart = nullptr;
	}
}
void UIntArr::create(int Length)
{
	arraystart = (unsigned int*)(ncalloc(Length, sizeof(unsigned int)));
	exist = true;
	length = Length;
}
//adds UIntArrs
UIntArr UIntArr::add(UIntArr AddArr)
{
	AddArr.exist = false;
	UIntArr NewArray(length + AddArr.length);
	NewArray.exist = false;
	id = 1;
	AddArr.id = 2;
	NewArray.id = 3;
	for (int i = 0; i < length; i++)
	{
		NewArray.arraystart[i] = arraystart[i];
	}
	for (int i = 0; i < AddArr.length; i++)
	{
		NewArray.arraystart[i + length] = AddArr.arraystart[i];
	}
	return NewArray;
}