/*
* File Name: curveCut.cpp
* Lab # and Assignment #: Lab 5 Exercise B
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 22 2020
*/

#include "square.h"
#include "circle.h"
#include "curveCut.h"
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

CurveCut::CurveCut(double x, double y, double sideA, double sideB, double radius, const char *name)
        : Shape(x, y, name), Rectangle(x, y, sideA, sideB, name), Circle(x, y, radius, name) {
    if (radius > min(sideA, sideB)){
        cerr << "Error, radius is larger than min(width, length), exiting..." << endl;
        exit(1);
    }
}

double CurveCut::area() const{
    return Rectangle::area() - (Circle::area() / 4);
}

double CurveCut::perimeter() const {
    return (Circle::perimeter() / 4) + (Rectangle::perimeter() - 2 * Circle::getRadius());
}

void CurveCut::display() const{
    cout << "CurveCut name: " << getName() << endl;
    getOrigin().display();
    cout << "Width: " << getSideA() << endl;
    cout << "Length: " << getSideB() << endl;
    cout << "Radius of the cut: " << getRadius() << endl;
}
