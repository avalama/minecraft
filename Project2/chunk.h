#pragma once
#include"Camera.h"
class chunk
{
public:
	cube CubeArr[16][16][256];
	cube* ArrayToBuffer[65536];
	floatarray result;
	unsigned int * CubeElement;
	int elementsize=0;
	int shapesize = 0;
	chunk(camera,int,int);
	void Move();
	void SortArrForBuffer();
	floatarray renderbuffer(camera);
};