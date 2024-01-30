#include "FloatArray.h"
floatarray::floatarray(float* arraystart, int length, bool IsStatic) :arraystart(arraystart), length(length),exist(!IsStatic)
{
	if (!IsStatic)
	{
		arraystart = (float*)(ncalloc(length, sizeof(float)));
	}
}	//creates and allocates a new array
floatarray::floatarray(int length) :length(length), exist(true)
{
		arraystart = (float*)(ncalloc(length, sizeof(float)));
}
floatarray::floatarray()
{
}
int des = 0;
floatarray::~floatarray()
{
	/*
	if (exist)
	{

		exist = false;
		if(*arraystart<-999999)
		{
			if (id != 10)
			{
				cout << "hi";
			}
			des++;
		}
	}*/
}
int getdes()
{
	return des;
}
void floatarray::create(int Length)
{
	arraystart = (float*)(ncalloc(Length, sizeof(float)));
	exist = true;
	length = Length;
}
//adds FloatArrays
floatarray floatarray::add(floatarray AddArr)
{
	floatarray NewArray(length+AddArr.length);
	for (int i = 0; i <length; i++)
	{
		NewArray.arraystart[i] = arraystart[i];
	}
	for (int i = 0; i < AddArr.length; i++)
	{
		NewArray.arraystart[i+length] = AddArr.arraystart[i];
	}
	free(AddArr.arraystart);
	AddArr.arraystart = nullptr;
	return NewArray;
}