 /*
* File Name: circle.cpp
* Lab # and Assignment #: Lab 5 Exercise B
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 22 2020
*/

#include "circle.h"
#include <iostream>
#include <math.h>

using namespace std;

Circle::Circle(double x, double y, double radius, const char *name)
       : Shape(x, y, name), radius(radius) {
}

double Circle::area() const {
    return 3.141592 * pow(getRadius(), 2);
}

double Circle::perimeter() const {
    return 2 * 3.141592 * getRadius();
}

void Circle::display() const { 
    cout << "Circle Name: " << getName() << endl;
    getOrigin().display();
    cout << "Radius: " << getRadius() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimiter: " << perimeter() << endl;
}
