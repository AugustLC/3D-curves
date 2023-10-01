
#include <iostream>
#include <cmath>
#include <ctime>
#include <vector>
#include <algorithm>
#include <memory>

#include "CircleCurve.h"
#include "EllipseCurve.h"
#include "HelixCurve.h"

using namespace std;

//aliases for smart pointers to the "Curve" and "CircleCurve" types
using CurvePtr = shared_ptr<Curve>;
using CircleCurvePtr = shared_ptr<CircleCurve>;

//function for comparing objects "CircleCurve" for the "sort" function
bool CircleCurveComparate(CircleCurvePtr i, CircleCurvePtr j)
{ 
    return (i->getRadius() < j->getRadius()); 
}

//creating a random circle curve
CurvePtr randomCircleCurve()
{
    return make_shared<CircleCurve>(Point3D{ 0.0, 0.0, 0.0 }, (double)(rand() % 10 + 1));
}

//creating a random ellipse curve
CurvePtr randomEllipseCurve()
{
    return make_shared<EllipseCurve>(Point3D{ 0.0, 0.0, 0.0 }, (double)(rand() % 10 + 1), (double)(rand() % 10 + 1));
}

//creating a random helix curve
CurvePtr randomHelixCurve()
{
    return make_shared<HelixCurve>(Point3D{ 0.0, 0.0, 0.0 }, (double)(rand() % 10 + 1), (double)(rand() % 9 + 1) / 10);
}

const double pi = acos(-1);

int main()
{
    srand(time(NULL));

    //vector of curves for all types
    vector<CurvePtr> curves;
    //vector of circular curves
    vector<CircleCurvePtr> circleCurves;

    //placing a random number of curves of different types in a container
    for (int i = 0; i < (rand() % 30 + 10); i++)
    {
        switch (rand() % 3)
        {
            case(0):
            {
                curves.push_back(randomCircleCurve());
                break;
            }
            case(1):
            {
                curves.push_back(randomEllipseCurve());
                break;
            }
            case(2):
            {
                curves.push_back(randomHelixCurve());
                break;
            }
        }
    }

    cout << "Coordinates of points of curves at t=PI/4" << endl;
    for (int i = 0; i < curves.size(); i++)
    {
        cout << (i + 1) << ") Type: " + curves[i]->getType();
        curves[i]->curveCoordinate(pi / 4).print();
    }

    cout << endl << endl << "Derivatives of curves at t=PI/4" << endl;
    for (int i = 0; i < curves.size(); i++)
    {
        cout << (i + 1) << ") Type: " + curves[i]->getType() << " ";
        curves[i]->curveVector(pi / 4).print();
    }

    //taking pointers to circular curves from the first vector
    for (int i = 0; i < curves.size(); i++)
    {
        if (curves[i]->getType() == "Circle")
        {
            circleCurves.push_back(dynamic_pointer_cast<CircleCurve>(curves[i]));
        }
    }

    //ascending sorting of circular curves
    sort(circleCurves.begin(), circleCurves.end(), CircleCurveComparate);
    
    double sumRadius = 0;

    //output of an ordered vector of circular curves
    cout << endl << endl << "Ordered vector of circular curves: " << endl;
    for (int i = 0; i < circleCurves.size(); i++)
    {
        cout << (i + 1) << ") Type: " + circleCurves[i]->getType() << " Radius: " << circleCurves[i]->getRadius() << endl;
        sumRadius += circleCurves[i]->getRadius();
    }
    
    //output of the sum of all radii of circular curves
    cout << endl << endl << "Sum of all radii of circular curves: " << sumRadius << endl;

    system("pause");

    return 0;
}

