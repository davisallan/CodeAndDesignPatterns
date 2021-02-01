/*
* File Name: rectangle.h
* Lab # and Assignment #: Lab 5 Exercise A
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 22 2020
*/

#include "square.h"

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle: public Square {
    public:
        Rectangle(double x, double y, double sideA, double sideB, const char *name);
        //  REQUIRES: name is pointing to the first char of a built-in string
        //  PROMISES: constructs a Rectangle object with its data member initialized 
        //  from the provided arguments

        const double getSideB() const {return sideB;};
        //  PROMISES: returns the length of sideB

        void setSideB(double newSideB) {sideB = newSideB;};
        //  PROMISES: sets the length of sideB to the provided argument

        double area() const;
        //  PROMISES: returns the area of the Rectangle

        double perimeter() const;
        //  PROMISES: returns the perimeter of the Rectangle

        void display() const;
        //  PROMISES: display all data members to the console

    protected:
        double sideB;
};

#endif