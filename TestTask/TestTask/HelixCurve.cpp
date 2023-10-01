#include "HelixCurve.h"

HelixCurve::HelixCurve(Point3D _center, double _radius, double _step)
{
    center = _center;
    radius = _radius;
    step = _step;
}

Point3D HelixCurve::curveCoordinate(double t)
{
    return Point3D
    {
        radius * t * cos(t) + center.x,
        radius * t * sin(t) + center.y,
        step * t + center.z
    };
}

Point3D HelixCurve::curveVector(double t)
{
    return Point3D
    {
        radius * (cos(t) - t * sin(t)),
        radius * (sin(t) + t * cos(t)),
        step
    };
}

string HelixCurve::getType()
{
    return "Helix";
}