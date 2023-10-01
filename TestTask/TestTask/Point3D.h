#pragma once

#include <iostream>
using namespace std;

struct Point3D
{
    double x{}, y{}, z{};
    void print()
    {
        cout << "X: " << x << " Y: " << y << " Z: " << z << endl;
    }
};
