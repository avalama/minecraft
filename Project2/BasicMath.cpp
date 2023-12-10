#include"BasicMath.h"
double square(double a)
{
    return(a * a);
}
double ArcSin(double num)
{
    return asin(num) * 180 / M_PI;
}
double ArcCos(double num)
{
    return acos(num) * 180 / M_PI;
}
double FindDistanceXY(position a, position b)
{
    return(sqrt(square(a.x - b.x) + square(a.y - b.y)));
}
double FindDistanceXZ(position a, position b)
{
    return(sqrt(square(a.x - b.x) + square(a.z - b.z)));
}
double FindDistanceYZ(position a, position b)
{
    return(sqrt(square(a.z - b.z) + square(a.y - b.y)));
}
double DegToRad(double ans)
{
    return ans / 180 * M_PI;
}