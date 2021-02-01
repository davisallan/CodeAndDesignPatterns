/*
* File Name: graphicsWorld.cpp
* Lab # and Assignment #: Lab 5 Exercise A/B
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 22 2020
*/

#include "point.h"
#include "graphicsWorld.h"
#include "square.h"
#include "rectangle.h"
#include "circle.h"
#include "curveCut.h"
#include <iostream>
using namespace std;

void GraphicsWorld::run() {
    cout << "\nProgram created by Davis Allan, 10016543\n\n";

#if 1 // Change 0 to 1 to test Point
    
    cout << "Testing functions in Class Point" << endl;

    Point m (6,8);
    Point n (6,8);
    cout << "\nTesting getCounter(), expected to display 2";
    cout << "\nThe number of points currently in existence are: " << Point::getCounter();
    cout << "\n\nExpected to display the point m, and expected output is:";
    cout << "\nX-coordinate: 6.00";
    cout << "\nY-coordinate: 8.00\n\n";

    m.display();
    n.setX(9);

    cout << "\nExpected to display the distance between m and n is: 3";
    cout << "\nThe distance between m and n is: " << m.dist(n);
    cout << "\nExpected second version of the distance function also print: 3";
    cout << "\nThe distance between m and n is again: " << Point::dist(m, n);

    Point o (10,12);
    Point p (5,10);
    cout << "\n\nTesting getCounter(), expected to display 4";
    cout << "\nThe number of points currently in existence are: " << Point::getCounter();
    cout << "\n\nDisplaying most recent point's id, expecting 1004";
    cout << "\nUnique id of Point p is: " << p.getID();
#endif // end of block to test Point

#if 1 // Change 0 to 1 to test Square
    
    cout << "\n--------------------------------------------------------";
    cout << "\nTesting Functions in class Square:\n\n";

    Square s(5, 7, 12, "SQUARE - S");
    s.display();
    cout << "\nTesting the move function, moving square a dx = 5, dy = -4"
        << "\nExpecting square to now be at coordinates x = 10.00, y = 3.00:\n\n";
    s.move(5, -4);
    s.display();

    cout << "\n\nTesting the copy constructor\n" << endl;
    Square sq1(s);
    s.setSideA(20);
    
    cout << "Expecting the following result for displaying sq1:\n" 
         << "Square Name: SQUARE - S\n" << "X-coordinate: 10.00\n"
         << "Y-coordinate: 3.00\n" << "Side a: 12\n" << "Area: 144\n"
         << "Perimeter: 48\n\n";
    
    sq1.display();

    cout << "\nTesting the assignment operator:\n" << endl;

    Square sq2(1,2,15,"sq2");
    sq2 = s;
    s.setSideA(10);

    cout << "Expecting the following result for displaying sq2:\n" 
         << "Square Name: SQUARE - S\n" << "X-coordinate: 10.00\n"
         << "Y-coordinate: 3.00\n" << "Side a: 20\n" << "Area: 400\n"
         << "Perimeter: 80\n\n";

    sq2.display();
    cout << "\n--------------------------------------------------------";
#endif // end of block to test Square

#if 1 // Change 0 to 1 to test Rectangle

    cout << "\n\nTesting Functions in class Rectangle:\n\n";

    Rectangle a(5, 7, 12, 15, "RECTANGLE A");
    a.display();
    cout << endl;
    Rectangle b(16 , 7, 8, 9, "RECTANGLE B");
    b.display();
    double d = a.distance(b);

    cout <<"\nDistance between square a, and b is: " << d << endl << endl;

    Rectangle rec1 = a;
    rec1.display();

    cout << "\nTesting assignment operator in class Rectangle:\n" <<endl;
    
    Rectangle rec2 (3, 4, 11, 7, "RECTANGLE rec2");
    rec2.display();
    rec2 = a;
    a.setSideB(200);
    a.setSideA(100);

    cout << "\nExpected to display the following values for objec rec2: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n" << "X-coordinate: 5.00\n" << "Y-coordinate: 7.00\n"
    << "Side a: 12\n" << "Side b: 15\n" << "Area: 180\n" << "Perimeter: 54\n" ;
    cout << "\nIf it doesn't there is a problem with your assignment operator.\n" << endl;

    rec2.display();

    cout << "\nTesting copy constructor in class Rectangle:" <<endl;

    Rectangle rec3 (a);
    rec3.display();
    a.setSideB(300);
    a.setSideA(400);

    cout << "\nExpected to display the following values for objec rec3: " << endl;
    cout << "Rectangle Name: RECTANGLE A\n" << "X-coordinate: 5.00\n" << "Y-coordinate: 7.00\n"
    << "Side a: 100\n" << "Side b: 200\n" << "Area: 20000\n" << "Perimeter: 600\n" ;

    rec3.display();
    cout << "\n--------------------------------------------------------";
#endif // end of block to test Rectangle
#if 1 // Change 0 to 1 to test using array of pointer and polymorphism
    
    cout << "\nTesting array of pointers and polymorphism:" <<endl;
    Shape* sh[4];
    sh[0] = &s;
    sh[1] = &b;
    sh [2] = &rec1;
    sh [3] = &rec3;
    sh [0]->display();
    sh [1]->display();
    sh [2]->display();
    sh [3]->display();
    cout << "\n--------------------------------------------------------";
#endif // end of block to test array of pointer and polymorphism

//EXERCISE B CODE:

#if 1
    cout << "\nTesting Functions in class Circle:" <<endl;

    Circle c (3, 5, 9, "CIRCLE C");
    c.display();

    cout << "\nthe area of " << c.getName() <<"  is: "<< c.area() << endl;
    cout << "the perimeter of " << c.getName() << " is: "<< c.perimeter() << endl;
    
    d = a.distance(c);
    
    cout << "\nThe distance between rectangle a and circle c is: " << d << endl << endl;
    cout << "\n--------------------------------------------------------";
    cout << "\n\nTesting Functions in class CurveCut:\n" <<endl;

    CurveCut rc (6, 5, 10, 12, 9, "CurveCut rc");
    rc.display();
   
    

    cout << "the area of " << rc.getName() <<" is: "<< rc.area();
    cout << "\nthe perimeter of " << rc.getName() << " is: "<< rc.perimeter();
    
    d = rc.distance(c);
    
    cout << "\n\nThe distance between rc and c is: " << d << endl;

    cout << "\nTesting copy constructor in class CurveCut:" <<endl;
    cout << "\nExpected to display the following values for objec cc: " << endl;
    cout << "Rectangle Name: CurveCurt rc\n" << "X-coordinate: 6.00\n" << "Y-coordinate: 5.00\n"
    << "Width: 12\n" << "Length: 10\n" << "Radius of the cut: 9\n" << endl;
    CurveCut cc (rc);
    rc.setSideB(40);
    cc.display();
    
    
    cout << "\nTesting assignment operator in class CurveCut:" <<endl;
    
    CurveCut cc2(2, 5, 100, 12, 9, "CurveCut cc2");
    
    cc2.display();
    cout << endl;
    cc2 = cc;
    cc2.display();
    cout << "\n--------------------------------------------------------\n";
    cout << "Testing array of pointers and polymorphism:" << endl;
    // Using array of Shape pointers:
    Shape* sha[4];
    sha[0] = &s;
    sha[1] = &a;
    sha [2] = &c;
    sha [3] = &rc;
    sha [0]->display();
    
    cout << "\nthe area of "<< sha[0]->getName() << " is: "<< sha[0] ->area();
    cout << "\nthe perimeter of " << sha[0]->getName () << " is: "<< sha[0]->perimeter() << endl << endl;
    
    sha [1]->display();
    
    cout << "\nthe area of "<< sha[1]->getName() << " is: "<< sha[1] ->area();
    cout << "\nthe perimeter of " << sha[1]->getName () << " is: "<< sha[1]->perimeter() << endl << endl;
    
    sha [2]->display();
    
    cout << "\nthe area of "<< sha[2]->getName() << " is: "<< sha[2] ->area();
    cout << "\nthe circumference of " << sha[2]->getName ()<< " is: "<< sha[2]->perimeter() << endl << endl;;
    
    sha [3]->display();
    
    cout << "\nthe area of "<< sha[3]->getName() << " is: "<< sha[3] ->area() << endl;
    cout << "the perimeter of " << sha[3]->getName () << " is: "<< sha[3]->perimeter() << endl;
    cout << "\n--------------------------------------------------------\n";

    
    
#endif

}

int main() {
    GraphicsWorld().run();
}