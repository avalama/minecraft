#include"Cube.h"
cube::cube(position p, float s, int id) :center(center), id(id)
{
    size = s;
    int d = rand();
    if (d % 3 == 0)
    {
         color={ 255,0,0 };
    };
    if (d % 3 == 1)
    {
         color={ 0,255,0 };
    }
    if (d % 3 == 2)
    {
         color={ 0,0,255 };
    }
    float copy[48] = 
    {
        -s+p.x,s+p.y,s+p.z, color.x,color.y,color.z,    //left up +front     0  
        s+p.x,s+p.y,s+p.z,color.x,color.y,color.z,     //right up front    1
        s+p.x,-s+p.y,s+p.z,color.x,color.y,color.z,    //right down front  2
        -s+p.x,-s+p.y,s+p.z,color.x,color.y,color.z,   //left dowm front   3
        -s+p.x,-s+p.y,-s+p.z,color.x,color.y,color.z,  //left down back    4
        -s+p.x,s+p.y,-s+p.z, color.x,color.y,color.z,  //left up back      5
        s+p.x,s+p.y,-s+p.z,color.x,color.y,color.z,   //right up back     6
        s+p.x,-s+p.y,-s+p.z,color.x,color.y,color.z  //right down back   7
    };
    center = p;

    for (int i = 0; i < CubeShapeLength; i++)
    {
        CubeShape[i] = copy[i];
    }
    CubeShapeArray.id = 9;
}
cube::cube()
{

}
cube::~cube()
{
}
void cube::Move()
{
    bool reset = GetAsyncKeyState(32);
    bool mup = (GetAsyncKeyState(87) && (*up + speed <= 1)), mdown = (GetAsyncKeyState(83) && *down - speed >= -1), mleft = (GetAsyncKeyState(65) && *left - speed >= -1), mright = (GetAsyncKeyState(68) && *right + speed <= 1), mfoward = (GetAsyncKeyState(69) && *foward + speed <= 1), mbackward = (GetAsyncKeyState(81) && *backward - speed >= -1);
    for (int i = 0; i < CubeShapeLength; i += VertexLength)
    {
        if (reset)
        {
            float CubeShape1[48] = {
        -size,size,size, CubeShape[3],CubeShape[4],CubeShape[5],    //left up front     0  
        size,size,size,CubeShape[3],CubeShape[4],CubeShape[5],     //right up front    1
        size,-size,size,CubeShape[3],CubeShape[4],CubeShape[5],    //right down front  2
        -size,-size,size,CubeShape[3],CubeShape[4],CubeShape[5],   //left dowm front   3
        -size,-size,-size,CubeShape[3],CubeShape[4],CubeShape[5],  //left down back    4
        -size,size,-size, CubeShape[3],CubeShape[4],CubeShape[5],  //left up back      5
        size,size,-size,CubeShape[3],CubeShape[4],CubeShape[5],   //right up back     6
        size,-size,-size,CubeShape[3],CubeShape[4],CubeShape[5]  //right down back   7
            };
            for (int i = 0; i < CubeShapeLength; i++)
            {
                CubeShape[i] = CubeShape1[i];
            }
            center = { 0,0,0 };
        }
        if (mright)
        {
            CubeShape[i] += speed;
        }
        if (mleft)
        {
            CubeShape[i] -= speed;
        }
        if (mdown)
        {
            CubeShape[i + 1] -= speed;
        }
        if (mup)
        {
            CubeShape[i + 1] += speed;
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
void cube::Move( bool greset,bool gup,bool gdown,bool gleft, bool gright, bool gfoward,bool gbackward)
{
    for (int i = 0; i < CubeShapeLength; i += VertexLength)
    {
        if (greset)
        {
            float CubeShape1[48] = {
        -size,size,size, CubeShape[3],CubeShape[4],CubeShape[5],    //left up front     0  
        size,size,size,CubeShape[3],CubeShape[4],CubeShape[5],     //right up front    1
        size,-size,size,CubeShape[3],CubeShape[4],CubeShape[5],    //right down front  2
        -size,-size,size,CubeShape[3],CubeShape[4],CubeShape[5],   //left dowm front   3
        -size,-size,-size,CubeShape[3],CubeShape[4],CubeShape[5],  //left down back    4
        -size,size,-size, CubeShape[3],CubeShape[4],CubeShape[5],  //left up back      5
        size,size,-size,CubeShape[3],CubeShape[4],CubeShape[5],   //right up back     6
        size,-size,-size,CubeShape[3],CubeShape[4],CubeShape[5]  //right down back   7
            };
            for (int i = 0; i < CubeShapeLength; i++)
            {
                CubeShape[i] = CubeShape1[i];
            }
            center = { 0,0,0 };
        }
        if(gright)
        {
            CubeShape[i] += speed;
        }
        if (gleft)
        {
            CubeShape[i] -= speed;
        }
        if (gdown)
        {
            CubeShape[i+1] -= speed;
        }
        if (gup)
        {
            CubeShape[i+1] += speed;
        }
        if (gbackward)
        {
            CubeShape[i + 2] -= speed;
        }
        if (gfoward)
        {
            CubeShape[i + 2] += speed;
        }
	};
    if (gright)
    {
        center.x += speed;
    }
    if (gleft)
    {
        center.x -= speed;
    }
    if (gdown)
    {
        center.y -= speed;
    }
    if (gup)
    {
        center.y += speed;
    }
    if (gbackward)
    {
        center.z -= speed;
    }
    if (gfoward)
    {
        center.z += speed;
    }
};
void cube::debug()
{
    system("cls");
    /*cout << "cube " << id<<endl<<endl;
    for (int i = 0; i < CubeShapeLength; i += VertexLength)
    {
        cout << CubeShape[i] << "  ,  " << CubeShape[i + 1] << "  ,  " << CubeShape[i + 2] << "  ,  " << CubeShape[i + 3] << "  ,  " << CubeShape[i + 4] << "  ,  " << CubeShape[i + 5] << endl;
    }*/
}
   // function for roots
   // double r = sqrt(9);