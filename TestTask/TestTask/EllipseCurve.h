#pragma once

#include "Curve.h"

//ellipse type curve class
class EllipseCurve : public Curve
{
private:
    Point3D center;
    double xRadius, yRadius;
public:
    EllipseCurve(Point3D _center, double _xRadius, double _yRadius);

    virtual ~EllipseCurve() {}

    virtual Point3D curveCoordinate(double t) override;

    virtual Point3D curveVector(double t) override;

    virtual string getType();
};