// lab3exe_A.cpp
// ENSF 619 Fall 2020 - Lab 3 Exercise A

#include <iostream>
using namespace std;

void moon(int& arg1, int* arg2);

void mars(const int& arg1, int*& arg2);

void jupiter(int& x);

int main()
{
    int arr[] = { 1500, 1100, 1600 };
    int& ref = arr[2];
    
    moon(ref, arr);
    ref++;
    cout << endl << arr[0] << "   " << arr[2] << endl;
    int* p = &arr[0];
    
    mars(arr[1] + 300, p);
    cout << endl << arr[0] << "   " << arr[0] << endl;
    
    return 0;
}

void moon(int& arg1, int* arg2)
{
    arg1++;
    (*arg2)++;
    cout << "arg1: " << arg1 << endl;
    cout << "arg2: " << *arg2 << endl;
    // point one
    
    return;
}

void mars(const int& arg1, int*& arg2)
{
    *arg2 = arg1 + 200;
    cout << "\nin mars: "<< arg1 << "   " << *arg2;
    jupiter(*arg2);
    cout << "\nin mars: "<< arg1 << "   " << *arg2;
    return;
}

void jupiter(int& x)
{
    cout << "\nin jupiter: "<< x;
    x += 100;
    cout << "\nin jupiter: "<< x;
    // point two
    
    return;
}
