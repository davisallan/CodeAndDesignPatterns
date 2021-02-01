/*
* File Name: curveCut.h
* Lab # and Assignment #: Lab 5 Exercise B
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 22 2020
*/

#include "circle.h"
#include "rectangle.h"

#ifndef CURVECUT_H
#define CURVECUT_H

class CurveCut: public Rectangle, public Circle {
    public:
        CurveCut(double x, double y, double sideA, double sideB, double radius, const char *name);
        //  REQUIRES: 
        //      radius <= min(width, length)   
        //      name is pointing to the first char of a built-in string
        //  PROMISES: constructs a CurveCut object with its data member initialized 
        //  from the provided arguments. Exits program if radius conditions not met.

        double area() const;
        //  PROMISES: returns the area of the CurveCut

        double perimeter() const;
        //  PROMISES: returns the perimeter of the CurveCut

        void display() const;
        //  PROMISES: display all data members to the console
};

#endif