 /*
* File Name: circle.h
* Lab # and Assignment #: Lab 5 Exercise B
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 22 2020
*/

#include "shape.h"

#ifndef CIRCLE_H
#define CIRCLE_H

class Circle: virtual public Shape {
    public:
        Circle(double x, double y, double radius, const char *name);
        //  REQUIRES: name is pointing to the first char of a built-in string
        //  PROMISES: constructs a Circle object with its data member initialized 
        //  from the provided arguments

        const double getRadius() const {return radius;};
        //  PROMISES: returns the radius of the Circle

        void setRadius(double newRad) {radius = newRad;}; 
        //  PROMISES: sets the radius to the provided argument

        double area() const;
        //  PROMISES: returns the area of the Circle

        double perimeter() const;
        //  PROMISES: returns the perimeter of the Rectangle

        void display() const;
        //  PROMISES: display all data members to the console
    protected:
        double radius;
};

#endif