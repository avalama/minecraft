#pragma once
#include"Camera.h"
class chunk
{
public:
	cube CubeArr[16][16];
	cube* ArrayToBuffer[256];
	floatarray result;
	unsigned int * CubeElement;
	chunk(int);
	void SortArrForBuffer();
	floatarray renderbuffer(camera);
};