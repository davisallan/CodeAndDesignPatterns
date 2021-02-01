/*
* File Name: shape.h
* Lab # and Assignment #: Lab 5 Exercise A
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 22 2020
*/

#include "point.h"

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
    public:
        Shape(double x, double y, const char *shapeName);
        //  REQUIRES: shapeName points to first char of built-in string
        //  PROMISES: Shape object created with its data members initialized from 
        //  the provided arguments
        
        virtual ~Shape();
        //  PROMISES: deallocates the dynamically allocated char array for the shape name
         
        Shape(const Shape& source); 
        //  REQUIRES: source is a reference to a Shape object
        //  PROMISES: constructs a new Shape object and deep copies the data members 
        //  of the source to the newly constructed Shape object
         
        Shape& operator=(const Shape& rhs); 
        //  REQUIRES: rhs is a reference to a Shape object
        //  PROMISES: copy and assign the data members of rhs object to the Shape object invoking 
        //  this assignment
        
        const Point& getOrigin() const {return origin;};
        //  PROMISES: returns a read only reference to the Point object representing the shapes origin

        const char* getName() const {return shapeName;};
        //  PROMISES: returns a read only pointer to the built in string containing the name of the shape

        virtual void display() const;
        //  PROMISES: displays the Shapes 

        virtual double area() const = 0;
        //  PROMISES: returns the area of the Shape

        virtual double perimeter() const = 0;
        //  PROMISES: returns the perimeter of the Shape

        double distance (const Shape& other) const;
        // REQUIRES: other is a reference to a Shape object
        // PROMISES: returns the calculated distance between the object invoking this method and the 
        // other shape

        static double distance(const Shape& the_shape, const Shape& other);
        //  REQUIRES: the_shape and other are references to Shape objects 
        //  PROMISES: returns the calculated distance between the the_shape and other Shape objects
        
        void move(double dx, double dy);
        // PROMISES: updates the Shape object's origin by dx and dy
        
    protected:
        Point origin;
        char *shapeName;
};

#endif