
#include "CircleCurve.h"


CircleCurve::CircleCurve(Point3D _center, double _radius)
{
    center = _center;
    radius = _radius;
}

Point3D CircleCurve::curveCoordinate(double t)
{
    return Point3D
    {
        radius * cos(t) + center.x,
        radius * sin(t) + center.y,
        center.z
    };
}

Point3D CircleCurve::curveVector(double t)
{
    return Point3D
    {
        -radius * sin(t),
        radius * cos(t)
    };
}

string CircleCurve::getType()
{
    return "Circle";
}

double CircleCurve::getRadius()
{
    return radius;
}


