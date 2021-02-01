/*
* File Name: shape.cpp
* Lab # and Assignment #: Lab 5 Exercise A
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 22 2020
*/

#include "point.h"
#include "shape.h"
#include <iostream>
#include <math.h>
#include <string.h>
#include <assert.h>
using namespace std;

Shape::Shape(double x, double y, const char *name): origin(Point(x,y)){
    shapeName = new char[strlen(name) + 1];
    assert(shapeName != NULL);
    strcpy(shapeName, name);
}

Shape::~Shape() {
    delete [] shapeName;
    shapeName = NULL;
}

Shape::Shape(const Shape& source): origin(Point(source.getOrigin().getX(), source.getOrigin().getY())) { 
    shapeName = new char[strlen(source.getName())];
    assert(shapeName != NULL);
    strcpy(shapeName, source.getName());
}

Shape& Shape::operator=(const Shape& rhs) {
    if (this != &rhs) {
        delete [] shapeName;
        shapeName = new char [strlen(rhs.getName())];
        assert(shapeName != NULL);
        strcpy(shapeName, rhs.getName());
        origin = Point(rhs.getOrigin().getX(), rhs.getOrigin().getY());
    }
    return *this;
}

void Shape::display() const {
    cout << "Shape Name: " << getName() << endl;
    getOrigin().display();
}


double Shape::distance(const Shape& other) const {
    return getOrigin().dist(other.getOrigin()); 
}

double Shape::distance(const Shape& the_shape, const Shape& other) {
    return the_shape.getOrigin().dist(the_shape.getOrigin(), other.getOrigin());
}

void Shape::move(double dx, double dy) {
    origin.setX(getOrigin().getX() + dx);
    origin.setY(getOrigin().getY() + dy);
}