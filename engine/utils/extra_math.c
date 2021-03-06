/*
=================================== ===== ==== === == = =  =   =    =     =
|File     : extra_math.c
|Author   : Thomas Heegaard
|Created  : 12/02/2014
|Purpose  : 
|
|Comments : 
|
=================================== ===== ==== === == = =  =   =    =     =
*/
#include <math.h>
#include <stdio.h>
#include "extra_math.h"

#define PI 3.14159265

double RotateOffsetX(double x_offset, double y_offset, double angle)
{
    angle *= PI / 180;
    return cos(angle)*x_offset - sin(angle)*y_offset;
}
double RotateOffsetY(double x_offset, double y_offset, double angle)
{
    angle *= PI / 180;
    return cos(angle)* y_offset + sin(angle)*x_offset; 
}
int Distance(int x_a, int y_a, int x_b, int y_b)
{
    int dx = x_b - x_a;
    int dy = y_b - y_a;
    return sqrt(dx*dx + dy*dy);
}

double VectorLength(Vector v)
{
    return sqrt(v.x*v.x + v.y*v.y);
}
Vector RotateVector(Vector vector, double angle)
{
    angle *= PI / 180;
    return (Vector)
    {
        cos(angle)*vector.x - sin(angle)*vector.y,
        cos(angle)*vector.y + sin(angle)*vector.x
    };
}
Vector AddVectors(Vector v, Vector u)
{
    return (Vector){v.x + u.x, v.y + u.y};
}
Vector VectorMult(Vector v, double x)
{
    return (Vector){v.x * x, v.y * x};
}
Vector unitaryVector(Vector v)
{
    return VectorMult(v, 1.0/VectorLength(v));
}
double DotProduct(Vector v, Vector u)
{
    return v.x*u.x + v.y*u.y;
}
Vector ProjectVector(Vector from, Vector to)
{
    return VectorMult(to, DotProduct(from, to)/DotProduct(to, to));
}

double DVectorLength(DVector v)
{
    return sqrt(v.x*v.x + v.y*v.y);
}
DVector RotateDVector(DVector vector, double angle)
{
    angle *= PI / 180;
    return (DVector)
    {
        cos(angle)*vector.x - sin(angle)*vector.y,
        cos(angle)*vector.y + sin(angle)*vector.x
    };
}
DVector AddDVectors(DVector v, DVector u)
{
    return (DVector){v.x + u.x, v.y + u.y};
}
DVector DVectorMult(DVector v, double x)
{
    return (DVector){v.x * x, v.y * x};
}
DVector unitaryDVector(DVector v)
{
    return DVectorMult(v, 1.0/DVectorLength(v));
}
double DDotProduct(DVector v, DVector u)
{
    return v.x*u.x + v.y*u.y;
}
DVector ProjectDVector(DVector from, DVector to)
{
    return DVectorMult(to, DDotProduct(from, to)/DDotProduct(to, to));
}

