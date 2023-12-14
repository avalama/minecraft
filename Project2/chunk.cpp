#include"chunk.h"
chunk::chunk(int)
{
	int place = 0;
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            position a = { 1 - (i / 16),-0.8,1 - (j / 16) };
            CubeArr[i][j] = cube(a, 0.5, 6);
            ArrayToBuffer[place] = &CubeArr[i][j];
            place++;
            CubeElement = CubeElement.add(CubeArr[i][j].element,);
        }
    }
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
    cout << cou<<endl;
    cou = 0;
}
floatarray chunk::renderbuffer(camera cam)
{
    SortArrForBuffer();
    for (int i = 0; i < sizeof(ArrayToBuffer) / sizeof(cube*); i++)
    {
        result=result.add(cam.RotateCube(ArrayToBuffer[i]));
    }

    return result;
}