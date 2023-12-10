#include"Cube.h"
cube::cube(position p,float s,int id):center(center),id(id)
{
    float copy[48] = 
    {
        -s+p.x,s+p.y,s+p.z, 255,0,0,    //left up +front     0  
        s+p.x,s+p.y,s+p.z,255,0,0,     //right up front    1
        s+p.x,-s+p.y,s+p.z,0,0,255,    //right down front  2
        -s+p.x,-s+p.y,s+p.z,255,0,0,   //left dowm front   3
        -s+p.x,-s+p.y,-s+p.z,0,0,255,  //left down back    4
        -s+p.x,s+p.y,-s+p.z, 0,0,255,  //left up back      5
        s+p.x,s+p.y,-s+p.z,0,255,0,   //right up back     6
        s+p.x,-s+p.y,-s+p.z,0,255,0  //right down back   7
    };
    for (int i = 0; i < CubeShapeLength; i++)
    {
        CubeShape[i] = copy[i];
    }
    CubeShapeArray.id = 9;
}
cube::~cube()
{
}
void cube::Move()
{
    bool reset = GetAsyncKeyState(32);
    bool mup = (GetAsyncKeyState(87) && (*up + speed <= 1)), mdown = (GetAsyncKeyState(83) && *down - speed >= -1), mleft = (GetAsyncKeyState(65) && *left - speed >= -1), mright = (GetAsyncKeyState(68) && *right + speed <= 1), mfoward = (GetAsyncKeyState(69) && *foward + speed <= 1), mbackward = (GetAsyncKeyState(81) && *backward + speed >= -1);
    for (int i = 0; i < CubeShapeLength; i += VertexLength)
    {
        if (reset)
        {
            float CubeShape1[48] = {
        -0.2f,0.2f,0.2f, 255,0,0,    //left up front     0  
        0.2f,0.2f,0.2f,255,0,0,     //right up front    1
        0.2f,-0.2f,0.2f,0,0,255,    //right down front  2
        -0.2f,-0.2f,0.2f,255,0,0,   //left dowm front   3
        -0.2f,-0.2f,-0.2f,0,0,255,  //left down back    4
        -0.2f,0.2f,-0.2f, 0,0,255,  //left up back      5
        0.2f,0.2f,-0.2f,0,255,0,   //right up back     6
        0.2f,-0.2f,-0.2f,0,255,0  //right down back   7
            };
            for (int i = 0; i < CubeShapeLength; i++)
            {
                CubeShape[i] = CubeShape1[i];
            }
        }
        if(mright)
        {
            CubeShape[i] += speed;
        }
        if (mleft)
        {
            CubeShape[i] -= speed;
        }
        if (mdown)
        {
            CubeShape[i+1] -= speed;
        }
        if (mup)
        {
            CubeShape[i+1] += speed;
        }
        if (mbackward)
        {
            CubeShape[i + 2] -= speed;
        }
        if (mfoward)
        {
            CubeShape[i + 2] += speed;
        }
	};
    if (mright)
    {
        center.x += speed;
    }
    if (mleft)
    {
        center.x -= speed;
    }
    if (mdown)
    {
        center.y -= speed;
    }
    if (mup)
    {
        center.y += speed;
    }
    if (mbackward)
    {
        center.z -= speed;
    }
    if (mfoward)
    {
        center.z += speed;
    }
};
   // function for roots
   // double r = sqrt(9);