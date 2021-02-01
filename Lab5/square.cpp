/*
* File Name: DynString.cpp
* Lab # and Assignment #: Lab 5 Exercise A
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 22 2020
*/

#include "square.h"
#include <iostream>
using namespace std;

Square::Square(double x, double y, double side, const char *name)
       : Shape(x, y, name), sideA(side) {}

double Square::area() const{
    return getSideA() * getSideA();
}

double Square::perimeter() const {
    return getSideA() * 4;
}

void Square::display() const {
    cout << "Square Name: " << getName() << endl;
    getOrigin().display();
    cout << "Side a: " << getSideA() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}