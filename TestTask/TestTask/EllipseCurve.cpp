#include "EllipseCurve.h"

EllipseCurve::EllipseCurve(Point3D _center, double _xRadius, double _yRadius)
{
    center = _center;
    xRadius = _xRadius;
    yRadius = _yRadius;
}

Point3D EllipseCurve::curveCoordinate(double t)
{
    return Point3D
    {
        xRadius * cos(t) + center.x,
        yRadius * sin(t) + center.y,
        center.z
    };
}

Point3D EllipseCurve::curveVector(double t)
{
    return Point3D
    {
        -xRadius * sin(t),
        yRadius * cos(t)
    };
}

string EllipseCurve::getType()
{
    return "Ellipse";
}