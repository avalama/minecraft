#pragma once
#include"Structs.h"
#include"Circle.h"
#include"FloatArray.h"
class cube
{
public:
    position center;
    position color;
    float speed = 0.4f;
    float size = 0.0f;
    float CubeShape[48];
    int id = 0;
    float* up = CubeShape + 1, * down = CubeShape + 13, * left = CubeShape, * right = CubeShape + 6, * foward = CubeShape + 2, * backward = CubeShape + 26;
    int CubeShapeLength = sizeof(CubeShape) / sizeof(float);
    floatarray CubeShapeArray{ CubeShape,CubeShapeLength,true };
    int VertexLength = CubeShapeLength / 8;
    unsigned int element[36]
    {
        //back down triangle
        5,4,7,
        //back up triangle
        5,6,7,
        //down down triangle
        4,7,2,
        //down up triangle
        4,3,2,
        //right down triangle
        1,2,7,
        //right up triangle
        1,6,7,
        //up down triangle
        0,1,6,
        //up up triangle
        0,5,6,
        //left down triangle
        0,3,4,
        //left up triangle
        0,5,4,
        //front down triangle
        0,3,2,
        //front up triangle
        0,1,2
    };
    int ElementLength = 36;
    //radius may change
    circle CubeCircle{ &center };
    float newZ;
    cube(position,float,int);
    cube();
    ~cube();
    void Move();
    void Move(bool, bool, bool, bool, bool, bool, bool );
    void debug();
};