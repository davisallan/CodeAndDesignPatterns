/*
* File Name: lab2exe_F.c
* Lab # and Assignment #: Lab 2 Exercise F
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

const int ARRAY_SIZE = 10;

/* a structure that represents a point on a Cartesian coordinates system. */
struct point
{
    char label[3];  // a label for a point
    double x ;      // x coordinate for point in a Cartesian coordinate system
    double y;       // y coordinate for point in a Cartesian coordinate system
    double z;       // z coordinate for point in a Cartesian coordinate system
};

void display_struct_point(struct point x);
double distance (const struct point* a, const struct point* b);
int search(const struct point* struct_array, const char* label, int n);

int main(void)
{
    
    struct point alpha = { "A1", 2.3, 4.5} ;
    struct point *stp = &alpha;
    printf("Size of struct-point in our Linux lab is: %d bytes.\n",
           (int) sizeof(struct point));
    printf("Size of strcut-point pointer in our Linux lab is: %d bytes.\n",
           (int) sizeof(stp));
    printf("Size of strcut that stp points to is:  %d bytes.\n",
           (int) sizeof(*stp));
    
    display_struct_point(*stp);
    
    struct point sigma = { "C1", 12.3, 14.5, 56.00 } ;
    struct point omega = { "D1", 125.9, 130.0, 97.00 } ;
    struct point theta = { "E1", 5.9, 303.0, 7.00 } ;
    display_struct_point(sigma);
    display_struct_point(omega);
    printf("\nThe distance between sigma and omega is: %10.2f", distance(&sigma, &omega));
    printf("\nThe distance between sigma and theta is: %10.2f", distance(&sigma, &theta));
    
    return 0;
}

void display_struct_point(struct point x)
{
    printf("\nPoint: %s <%.2lf, %.2lf, %.2lf>", x.label, x.x, x.y, x.z);
}


double distance(const struct point* p1, const struct point* p2)
{
    // This funciton is incomplete and needs to be changed and complted by
    // the students to calculate and return the distance betwn the two three-D points
    double x_diff = p2->x - p1->x;
    double y_diff = p2->y - p1->y;
    double z_diff = p2->z - p1->z;

    return sqrt((pow(x_diff, 2) + pow(y_diff, 2) + pow(z_diff, 2)));
}
