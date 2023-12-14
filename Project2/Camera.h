#pragma once
#include"Structs.h"
#include"Circle.h"
#include"FloatArray.h"
#include"Cube.h"
class camera
{
public:
    POINT LongCurs;
    DPOINT CursorPos, lastCursorPos,resolution;
    //how much left/left i moved compeard to screen
    double xscreen = 0;
    //how much up/dowm i moved compared to screen
    double yscreen = 0;
    position CameraPosition{ 0,0,1 };
    double LookingDegreesXY = 0;
    double LookingDegreesYZ = 0;
    double LookingDegreesXZ = 0;
    double AbsLookingDegreesXY = 0;
    double AbsLookingDegreesYZ = 0;
    double AbsLookingDegreesXZ = 0;
    double rotatedeg = 0;
    camera();
    ~camera();
    void getinput(bool*);
    void GetMouseChanges();
    position AddDegreesXY(circle, position);
    position AddDegreesXZ(circle, position);
    position AddDegreesYZ(circle, position);
    position AbsAddDegreesXY(circle, position);
    position AbsAddDegreesXZ(circle, position);
    position AbsAddDegreesYZ(circle, position);
    position rotateAroundCameraXZ(circle, position);
    position ScaleByDistance(cube*,position);
    position MakeDepth(position);
    floatarray RotateCube(cube*);
    floatarray ArrayToBuffer;
};
