#pragma once

#include "Curve.h"

//curve class of the helix type
class HelixCurve : public Curve
{
private:
    Point3D center;
    double radius, step;
public:
    HelixCurve(Point3D _center, double _radius, double _step);

    virtual ~HelixCurve() {}

    virtual Point3D curveCoordinate(double t) override;

    virtual Point3D curveVector(double t) override;

    virtual string getType();
};

