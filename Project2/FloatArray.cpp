#include "FloatArray.h"
floatarray::floatarray(float* arraystart, int length, bool IsStatic) :arraystart(arraystart), length(length),exist(!IsStatic)
{
	if (!IsStatic)
	{
		arraystart = (float*)(calloc(length, sizeof(float)));
	}
}	//creates and allocates a new array
floatarray::floatarray(int length) :length(length), exist(true)
{
		arraystart = (float*)(calloc(length, sizeof(float)));
}
floatarray::floatarray()
{
}
floatarray::~floatarray()
{
	if (exist)
	{
		exist = false;
		free(arraystart);
	}
}
void floatarray::create(int Length)
{
	arraystart = (float*)(calloc(Length, sizeof(float)));
	exist = true;
	length = Length;
}
//adds FloatArrays
floatarray floatarray::add(floatarray AddArr)
{
	AddArr.exist = false;
	floatarray NewArray(length+AddArr.length);
	NewArray.exist = false;
	id = 1;
	AddArr.id = 2;
	NewArray.id=3;
	for (int i = 0; i <length; i++)
	{
		NewArray.arraystart[i] = arraystart[i];
	}
	for (int i = 0; i < AddArr.length; i++)
	{
		NewArray.arraystart[i+length] = AddArr.arraystart[i];
	}
	return NewArray;
}