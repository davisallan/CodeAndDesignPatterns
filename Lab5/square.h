/*
* File Name: square.h
* Lab # and Assignment #: Lab 5 Exercise A
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 22 2020
*/

#include "shape.h"

#ifndef SQUARE_H
#define SQUARE_H

class Square: virtual public Shape {
    public:
        Square(double x, double y, double side, const char *name);
        //  REQUIRES: name is pointing to the first char of a built-in string
        //  PROMISES: constructs a Square object with its data member initialized 
        //  from the provided arguments

        const double getSideA() const {return sideA;};
        //  PROMISES: returns the length of sideA

        void setSideA(double newSide) {sideA = newSide;};
        //  PROMISES: sets the length of sideA to the provided argument

        double area() const;
        //  PROMISES: returns the area of the Rectangle

        double perimeter() const;
        //  PROMISES: returns the perimeter of the Rectangle

        void display() const;
        //  PROMISES: display all data members to the console
    protected:
        double sideA;
};

#endif