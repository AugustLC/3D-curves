#pragma once

#include "Point3D.h"

//base class for curves
class Curve
{
protected:
    Point3D center{};

    Curve() = default;
    Curve(Point3D _center) : center{ _center } {}
public:
    virtual ~Curve() {}
    //the output function of a three-dimensional point at t
    virtual Point3D curveCoordinate(double t) = 0;
    //the output function of the first derivative at t
    virtual Point3D curveVector(double t) = 0;
    //object type output function
    virtual string getType() = 0;
};