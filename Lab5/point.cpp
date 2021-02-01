/*
* File Name: point.cpp
* Lab # and Assignment #: Lab 5 Exercise A
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 22 2020
*/

#include "point.h"
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int Point::counter = 0;

Point::Point(double x, double y): xCoord(x), yCoord(y) {
    id = 1001 + counter++;
}

Point::~Point(){
    counter--;
}

Point::Point(const Point& source): xCoord(source.getX()), yCoord(source.getY()) {
    id = 1001 + counter++;
}

Point& Point::operator=(const Point& rhs) {
    if (this != &rhs) {
        xCoord = rhs.getX();
        yCoord = rhs.getY();
        id = 1001 + counter++;
    }
    return *this;
}

void Point::display() const {
    streamsize def = cout.precision();
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "X-coordinate: " << getX() << endl;
    cout << "Y-coordinate: " << getY() << endl;
    cout.unsetf(ios::fixed);
    cout.precision(def);
}

int Point::getCounter() {
    return counter;
}

double Point::dist(const Point& a) const {
    return sqrt(pow((getX() - a.getX()), 2) + (pow((getY() - a.getY()),2)));
}

double Point::dist(const Point& a, const Point& b) {
    return sqrt(pow((a.getX() - b.getX()), 2) + (pow((a.getY()- b.getY()),2)));
}

