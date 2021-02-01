 /*
* File Name: point.h
* Lab # and Assignment #: Lab 5 Exercise A
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 22 2020
*/

#ifndef POINT_H
#define POINT_H 

class Point {
    public:
        Point(double x, double y);
        // PROMISES: Point object created with all x and y initialized from 
        //the given arguments. Increments the counter for the number of points 
        //existence
        
        ~Point();
        // PROMISES: decrement the counter for the number of points in existence

        Point(const Point& source);
        //  REQUIRES: source is a reference to a Point object
        //  PROMISES: constructs a new Point object and deep copies the data members 
        //  of the source to the newly constructed Shape object. Increments the point counter

        Point& operator=(const Point& rhs); 
        //  REQUIRES: rhs is a reference to a Point object
        //  PROMISES: copy and assign the data members of rhs object to the Point object invoking 
        //  this assignment

        const double getX() const {return xCoord;};
        // PROMISES: returns the x-coordinate of the point 

        void setX(double x) {xCoord = x;};
        // PROMISES: sets the point object's x-coordinate to given the argument 

        const double getY() const {return yCoord;};
        // PROMISES: returns the y-coordinate of the point

        void setY(double y) {yCoord = y;};
        // PROMISES: sets the Point object's x-coordinate to given the argument 

        const int getID() {return id;};
        // PROMISES: returns the unique id of the point

        void display() const;
        // PROMISES: displays the point objects data members to the console
        
        static int getCounter();
        // PROMISES: returns the number of objects of class Point

        double dist(const Point& a) const;
        // PROMISES: calculates the distance between the object invoking the method,
        // and the point in the argument

        static double dist(const Point& a, const Point& b);
        // PROMISES: calculates and returns the distance between the two points 

    private:
        static int counter;
        int id;
        double xCoord;
        double yCoord;
};

#endif