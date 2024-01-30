#include"chunk.h"
#include"OutOfClassFunctions.h"
chunk::chunk(camera cam,int x,int z)
{
	int place = 0;
    CubeElement = (unsigned int*)ncalloc(9216 , sizeof(unsigned int));
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            position a = { i-8+(x*16),-3.5,j-8+(z*16)};
            CubeArr[i][j] = cube(a, 0.5, 6);
            ArrayToBuffer[place] = &CubeArr[i][j];
            place++;
            CubeElement = add(CubeElement,elementsize, CubeArr[i][j].element, CubeArr[i][j].ElementLength);
            elementsize += CubeArr[i][j].ElementLength;
            shapesize += CubeArr[i][j].CubeShapeLength;
        }
    }
    renderbuffer(cam);
    result.id = 12;
}
void chunk::SortArrForBuffer()
{
    double biggest = -999999999;
    cube* n;
    for (int i = 0; i < sizeof(ArrayToBuffer) / sizeof(cube*); i++)
    {
        for (int j = i; j < sizeof(ArrayToBuffer) / sizeof(cube*); j++)
        {
            if ((ArrayToBuffer[j]->center.z > biggest))
            {
                biggest = ArrayToBuffer[i]->center.z;
                n = ArrayToBuffer[j];
                ArrayToBuffer[j] = ArrayToBuffer[i];
                ArrayToBuffer[i] = n;
            }
        }
        biggest = -999999999;
    }
    //cout << "done";
}
floatarray chunk::renderbuffer(camera cam)
{
    result.create(0);
    floatarray  save1;
    for (int i = 0;i<256; i++)
    {
        save1=result.add(cam.RotateCube(ArrayToBuffer[i]));
        free(result.arraystart);
        result.arraystart = nullptr;
        result = save1;
    }
    SortArrForBuffer();
    return result;
}
void chunk::Move()
{
    bool reset = GetAsyncKeyState(32);
    bool up = GetAsyncKeyState(87), down = GetAsyncKeyState(83), left = GetAsyncKeyState(65), right = GetAsyncKeyState(68), foward = GetAsyncKeyState(69) , backward = GetAsyncKeyState(81);
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            CubeArr[i][j].Move(reset, up, down, left, right, foward, backward);
        }
    }
}