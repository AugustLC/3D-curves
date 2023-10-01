#pragma once

#include "Curve.h"

//curve class of the circle type
class CircleCurve : public Curve
{
private:
    double radius;
public:
    CircleCurve() = default;
    CircleCurve(Point3D _center, double _radius);

    ~CircleCurve() {}

    Point3D curveCoordinate(double t) override;

    Point3D curveVector(double t) override;

    string getType() override;

    double getRadius();
};
