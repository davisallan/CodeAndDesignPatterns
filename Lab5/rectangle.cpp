/*
* File Name: rectangle.cpp
* Lab # and Assignment #: Lab 5 Exercise A
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 22 2020
*/

#include "rectangle.h"
#include "square.h"
#include <math.h>
#include <iostream>
using namespace std;

Rectangle::Rectangle(double x, double y, double sideA, double sideB, const char *name)
        : Shape(x, y, name), Square(x, y, sideA, name), sideB(sideB) {
}

double Rectangle::area() const {
    return getSideA() * getSideB();
}

double Rectangle::perimeter() const {
    return (2 * getSideA()) + (2 * getSideB());
}

void Rectangle::display() const {
    cout << "Rectangle Name: " << getName() << endl;
    getOrigin().display();
    cout << "Side a: " << getSideA() << endl;
    cout << "Side b: " << getSideB() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimiter: " << perimeter() << endl;
}