#include"chunk.h"
#include"OutOfClassFunctions.h"
chunk::chunk(int,camera cam)
{
	int place = 0;
    CubeElement = (unsigned int*)calloc(9216 , sizeof(unsigned int));
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            position a = { 1 - (float(i) / 16),1 - (float(j) / 16),0 };
            CubeArr[i][j] = cube(a, 0.5, 6);
            ArrayToBuffer[place] = &CubeArr[i][j];
            place++;
            CubeElement = add(CubeArr[i][j].element,elementsize, CubeArr[i][j].element, CubeArr[i][j].ElementLength);
            elementsize += CubeArr[i][j].ElementLength;
        }
    }
    renderbuffer(cam);
}
int cou=0;
bool check(bool a)
{
    cou++;
    return a;
}
void chunk::SortArrForBuffer()
{
    double smallest = 999999999;
    cube* n;

    for (int k = 0; k < sizeof(ArrayToBuffer) / sizeof(cube*); k++)
    {
        cout << ArrayToBuffer[k]->center.z << ",";
    }
    cout << endl << endl;
    for (int i = 0; i < sizeof(ArrayToBuffer) / sizeof(cube*); i++)
    {
        smallest = 999999;
        for (int j = i; j < sizeof(ArrayToBuffer) / sizeof(cube*); j++)
        {
            if (check(ArrayToBuffer[j]->center.z < smallest))
            {
                smallest = ArrayToBuffer[i]->center.z;
                n = ArrayToBuffer[j];
                ArrayToBuffer[j] = ArrayToBuffer[i];
                ArrayToBuffer[i] = n;
            }
        }
    }
    cout << cou << endl;
    cou = 0;
}
floatarray chunk::renderbuffer(camera cam)
{
    result.~floatarray();
    result.create(0);
    for (int j = 0; j<16; j++)
    {
        for (int i = 0;i<16; i++)
        {
            result = result.add(cam.RotateCube(&CubeArr[i][j]));
        }
    }
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