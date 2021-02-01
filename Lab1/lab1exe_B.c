/*
* File Name: lab1exe_B.c
* Lab # and Assignment #: Lab 1 Exercise B
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: 09-22-2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    int n;
    double velocity;
    
    printf ("Please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
    
    create_table(velocity);
    return 0;
}

void create_table(double v) {
    double degrees[19];
    double radians[19];
    double deg = 0.0;

    for (int i = 0; i < 19; i++) { 
        degrees[i] = deg;
        radians[i] = degree_to_radian(deg);
        deg += 5;
    }

    printf("%s \t\t  %s\t\t   %s\n", "Angle", "t", "d");
    printf("%s \t\t %s\t\t  %s\n", "(deg)", "(sec)", "(m)");
    
    for (int i = 0; i < 19; i++) {
        double time = Projectile_travel_time(radians[i], v);
        double dist = Projectile_travel_distance(radians[i], v);
        printf("%6.3lf \t\t%6.3lf \t\t%6.3lf\n", degrees[i], time, dist);
    }

}

double Projectile_travel_time(double a, double v) {
    return (2 * v * sin(a)) / G;
}

double Projectile_travel_distance(double a, double v) {
    return (pow(v, 2) / G) * sin(2 * a);
}

double degree_to_radian(double d) {
    return d * (PI / 180.0);
}
