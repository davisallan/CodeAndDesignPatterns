/*
* File Name: DynString.cpp
* Lab # and Assignment #: Lab 5 Exercise A
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: 
*/

#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double x, double y);
    /* Create point object and initializes data members
    *   REQUIRES:
    *       
    *   PROMISES:
    *       
    */

    int getX();
    /* 
    *
    */

    int setX();
    /* 
    *
    */

    int getY();
    /* 
    *
    */

    int setY();
    /* 
    *
    */

    void display();
    /* 
    *
    */

    int counter();
    /* 
    *
    */

    double distance(Point a);
    /* 
    *
    */

    static double distance(Point a, Point b);
    /* 
    *
    */

private:
    static int idNum;
    int id;
    double x;
    double y;
};

#endif