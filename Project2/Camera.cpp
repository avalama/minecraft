#pragma once
#include"Camera.h"
#include"BasicMath.h"
#include"OutOfClassFunctions.h"
camera::camera()
{
    GetCursorPos(&LongCurs);
    lastCursorPos.x = LongCurs.x;
    lastCursorPos.y = LongCurs.y;
    CursorPos = lastCursorPos;
    resolution = GetScreenResolution();
    ArrayToBuffer.id = 13;
}
camera::~camera()
{
}
void camera::getinput(bool* cirrights)
{
    if (GetAsyncKeyState(32))
    {
         LookingDegreesXY = 0;
         LookingDegreesXZ = 0;
         LookingDegreesYZ = 0;
         AbsLookingDegreesXY = 0;
         AbsLookingDegreesXZ = 0;
         AbsLookingDegreesYZ = 0;
         rotatedeg = 0;
    }
    if (cirrights[10] && GetAsyncKeyState(27))
    {
        cirrights[10] = false;
        rotatedeg += 1;
        if ( rotatedeg > 360)
        {
             rotatedeg -= 360;
        }
    }
    if (cirrights[1] && GetAsyncKeyState(49))
    {
        cirrights[1] = false;
         LookingDegreesXY += 1;
        if ( LookingDegreesXY > 360)
        {
             LookingDegreesXY -= 360;
        }
    }
    if (cirrights[2] && GetAsyncKeyState(50))
    {
        cirrights[2] = false;
         LookingDegreesXZ += 1;
        if ( LookingDegreesXZ > 360)
        {
             LookingDegreesXZ -= 360;
        }
    }
    if (cirrights[3] && GetAsyncKeyState(51))
    {
        cirrights[3] = false;
         LookingDegreesYZ += 1;
        if ( LookingDegreesYZ > 360)
        {
             LookingDegreesYZ -= 360;
        }


    }
    if (cirrights[4] && GetAsyncKeyState(52))
    {
        cirrights[4] = false;
         LookingDegreesXY -= 1;
        if ( LookingDegreesXY > 360)
        {
             LookingDegreesXY -= 360;
        }
    }
    if (cirrights[5] && GetAsyncKeyState(53))
    {
        cirrights[5] = false;
         LookingDegreesXZ -= 1;
        if ( LookingDegreesXZ > 360)
        {
             LookingDegreesXZ -= 360;
        }
    }
    if (cirrights[6] && GetAsyncKeyState(54))
    {
        cirrights[6] = false;
         LookingDegreesYZ -= 1;
        if ( LookingDegreesYZ > 360)
        {
             LookingDegreesYZ -= 360;
        }
    }
    if (cirrights[7] && GetAsyncKeyState(55))
    {
        cirrights[7] = false;
         AbsLookingDegreesXY += 1;
        if ( AbsLookingDegreesXY > 360)
        {
             AbsLookingDegreesXY -= 360;
        }
    }
    if (cirrights[8] && GetAsyncKeyState(56))
    {
        cirrights[8] = false;
         AbsLookingDegreesXZ += 1;
        if ( AbsLookingDegreesXZ > 360)
        {
             AbsLookingDegreesXZ -= 360;
        }
    }
    if (cirrights[9] && GetAsyncKeyState(57))
    {
        cirrights[9] = false;
         AbsLookingDegreesYZ += 1;
        if ( AbsLookingDegreesYZ > 360)
        {
             AbsLookingDegreesYZ -= 360;
        }
    }
}
void camera::GetMouseChanges()
{
        /*if (GetAsyncKeyState(9))
        {
            SetCursorPos(resolution.x / 2,resolution.y / 2);
            xscreen = 0;
            yscreen = 0;
        }*/
        GetCursorPos(&LongCurs);
        CursorPos.x = LongCurs.x;
        CursorPos.y = LongCurs.y;            
        xscreen += 2*((lastCursorPos.x - CursorPos.x) / resolution.x);
        lastCursorPos.x = CursorPos.x;
        yscreen += 2*((lastCursorPos.y - CursorPos.y) / resolution.y);
        lastCursorPos.y = CursorPos.y;
}
floatarray camera::RotateCube(cube* cube)
{
    bool out = false;
    floatarray ArrayToBuffer{ cube->CubeShapeLength };
    ArrayToBuffer.id = 8;
    for (int i = 0; i < cube->CubeShapeLength; i += cube->VertexLength)
    {
        out = false;
        position rotpos{ cube->CubeShape[i],cube->CubeShape[i + 1],cube->CubeShape[i + 2] };
        if (LookingDegreesXY != 0)
        {
            rotpos = AddDegreesXY(cube->CubeCircle, rotpos);
        }
        if (LookingDegreesXZ != 0)
        {
            rotpos = AddDegreesXZ(cube->CubeCircle, rotpos);
        }
        if (LookingDegreesYZ != 0)
        {
            rotpos = AddDegreesYZ(cube->CubeCircle, rotpos);
        }
        if (AbsLookingDegreesXY != 0)
        {
            rotpos = AbsAddDegreesXY(cube->CubeCircle, rotpos);
        }
        if (AbsLookingDegreesXZ != 0)
        {
            rotpos = AbsAddDegreesXZ(cube->CubeCircle, rotpos);
        }
        if (AbsLookingDegreesYZ != 0)
        {
            rotpos = AbsAddDegreesYZ(cube->CubeCircle, rotpos);
        }
        if (rotatedeg != 0)
        {
            rotpos = rotateAroundCameraXZ(cube->CubeCircle, rotpos);
        }
        rotpos.x += 2 * xscreen;
        rotpos.y -= 2 * yscreen;
        if (rotpos.z < -1)
        {
            out = true;
        }
        rotpos = ScaleByDistance(cube, rotpos);
        if (out)
        {
            rotpos.z = -99;
        }
        ArrayToBuffer.arraystart[i] = rotpos.x;
        ArrayToBuffer.arraystart[i + 1] = rotpos.y;
        ArrayToBuffer.arraystart[i + 2] = rotpos.z;
        ArrayToBuffer.arraystart[i + 3] = cube->CubeShape[i + 3];
        ArrayToBuffer.arraystart[i + 4] = cube->CubeShape[i + 4];
        ArrayToBuffer.arraystart[i + 5] = cube->CubeShape[i + 5];
    }
    return ArrayToBuffer;
}
position camera::AddDegreesXY(circle RotCircle, position PastPos)
{
	double ArcCaculation = ArcSin((PastPos.x - RotCircle.center->x) / FindDistanceXY(PastPos, *RotCircle.center));
	//getting second arcsin degree
	if (PastPos.y < RotCircle.center->y)
	{
		ArcCaculation = 180 - ArcCaculation;
	}
	//arcsin can give 2 answers carefull
	double degree = LookingDegreesXY + ArcCaculation;
	position a = { float((sin(DegToRad(degree))) * FindDistanceXY(PastPos,*RotCircle.center)) + RotCircle.center->x, float(cos(DegToRad(degree)) * FindDistanceXY(PastPos,*RotCircle.center)) + RotCircle.center->y, PastPos.z };
	return a;
}
position camera::AddDegreesXZ(circle RotCircle, position PastPos)
{
	double ArcCaculation = ArcSin((PastPos.x - RotCircle.center->x) / FindDistanceXZ(PastPos, *RotCircle.center));
	//getting second arcsin degree
	if (PastPos.z < RotCircle.center->z)
	{
		ArcCaculation = 180 - ArcCaculation;
	}
	double degree = LookingDegreesXZ + ArcCaculation;
	position a = { float(sin(DegToRad(degree)) * FindDistanceXZ(PastPos,*RotCircle.center)) + RotCircle.center->x, PastPos.y , float(cos(DegToRad(degree)) * FindDistanceXZ(PastPos,*RotCircle.center)) + RotCircle.center->z };
	return a;
}
position camera::AddDegreesYZ(circle RotCircle, position PastPos)
{
	double ArcCaculation = ArcSin((PastPos.z - RotCircle.center->z) / FindDistanceYZ(PastPos, *RotCircle.center));
	//getting second arcsin degree
	if (PastPos.y < RotCircle.center->y)
	{
		ArcCaculation = 180 - ArcCaculation;
	}
	double degree = LookingDegreesYZ + ArcCaculation;
	position a = { PastPos.x, float(cos(DegToRad(degree)) * FindDistanceYZ(PastPos,*RotCircle.center)) + RotCircle.center->y, float(sin(DegToRad(degree)) * FindDistanceYZ(PastPos,*RotCircle.center)) + RotCircle.center->z };
	return a;
}
position camera::AbsAddDegreesXY(circle RotCircle, position PastPos)
{
	double ArcCaculation = ArcSin((PastPos.x) / FindDistanceXY(PastPos, { 0, 0, 0 }));
	//getting second arcsin degree
	if (PastPos.y < RotCircle.center->y)
	{
		ArcCaculation = 180 - ArcCaculation;
	}
	//arcsin can give 2 answers carefull
	double degree = AbsLookingDegreesXY + ArcCaculation;
	position a = { float((sin(DegToRad(degree))) * FindDistanceXY(PastPos, { 0, 0, 0 })) + RotCircle.center->x, float(cos(DegToRad(degree)) * FindDistanceXY(PastPos, { 0, 0, 0 })) + RotCircle.center->y, PastPos.z };
	return a;
}
position camera::AbsAddDegreesXZ(circle RotCircle, position PastPos)
{
	double ArcCaculation = ArcSin((PastPos.x) / FindDistanceXZ(PastPos, { 0, 0, 0 }));
	//getting second arcsin degree
	if (PastPos.z < RotCircle.center->z)
	{
		ArcCaculation = 180 - ArcCaculation;
	}
	double degree = AbsLookingDegreesXZ + ArcCaculation;
	position a = { float(sin(DegToRad(degree)) * FindDistanceXZ(PastPos, { 0, 0, 0 })) + RotCircle.center->x, PastPos.y , float(cos(DegToRad(degree)) * FindDistanceXZ(PastPos, { 0, 0, 0 })) + RotCircle.center->z };
	return a;
}
position camera::AbsAddDegreesYZ(circle RotCircle, position PastPos)
{
	double ArcCaculation = ArcSin((PastPos.z) / FindDistanceYZ(PastPos, { 0, 0, 0 }));
	//getting second arcsin degree
	if (PastPos.y < RotCircle.center->y)
	{
		ArcCaculation = 180 - ArcCaculation;
	}
	double degree = AbsLookingDegreesYZ + ArcCaculation;
	position a = { PastPos.x, float(cos(DegToRad(degree)) * FindDistanceYZ(PastPos, { 0, 0, 0 })) + RotCircle.center->y, float(sin(DegToRad(degree)) * FindDistanceYZ(PastPos, { 0, 0, 0 })) + RotCircle.center->z };
	return a;
}
position camera::rotateAroundCameraXZ(circle RotCircle, position PastPos)
{
	double rad = FindDistanceXZ(PastPos, CameraPosition);
	double dar = (PastPos.x) / FindDistanceXZ(PastPos, CameraPosition);
	double ArcCaculation = ArcSin((PastPos.x) / FindDistanceXZ(PastPos, CameraPosition));
	//getting second arcsin degree
	double degree = rotatedeg + ArcCaculation;
	position a = { float(sin(DegToRad(degree)) * FindDistanceXZ(PastPos, CameraPosition)) + CameraPosition.x, PastPos.y ,-( float(cos(DegToRad(degree)) * FindDistanceXZ(PastPos, CameraPosition)) )+ CameraPosition.z };
	if (rotatedeg == 90)
	{
		cout <<a.x<<"," << a.y << "," << a.z << endl;
	}
	return a;
}
position camera::ScaleByDistance(cube* cube1,position pastpos)
{
    position a;
    double distance = 1+ (abs(CameraPosition.z - pastpos.z));
    a.x = pastpos.x / distance;
    a.y = pastpos.y / distance;
    a.z = pastpos.z / distance;
    /*if (a.x >= -1 && a.x <= 1 && a.y >= -1 && a.y <= 1 && a.z >= -1 && a.z <= 1)
    {
        cout << "s";
    }*/
    return a;
}
//not used now idk dumb
position camera::MakeDepth( position pastpos)
{
    position a;
    double distance = 2 - (abs(CameraPosition.z - pastpos.z) / (2));
    a.x = pastpos.x * (distance);
    a.y = pastpos.y * (distance);
    a.z = pastpos.z ;
     return pastpos;
}