//  ENSF 619 Fall 2020 Lab 4 - Exercise C
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string.h>

const int size = 6;
using namespace std;
struct City {
    double x, y;
    char name[30];
};

void write_binary_file(City cities[], int size, char* filename);
/* PROMISES: attaches an ofstream object to a binary file named "filename" and
 * writes the content of the array cities into the file.
 */

void print_from_binary(char* filename);
/* PROMISES: uses ifstream library object to open the binary file named
 * "filename", reads the content of the file which are objects of struct City
 * (one record at a time), and displays them on the screen. It also saves the records
 * into a text-file that its name must be the filename argument, but with the extension
 * of .txt
 */


int main() {
    char bin_filename[] = "cities.bin";
    
    City cities[size] = {{100, 50, "Calgary"},
        {100, 150, "Edmonton"},
        {50, 50, "Vancouver"},
        {200, 50, "Regina"},
        {500, 50, "Toronto"},
        {200, 50, "Montreal"}};
    
    write_binary_file(cities, size, bin_filename);
    cout << "\nThe content of the binary file is:" << endl;
    print_from_binary(bin_filename);
    return 0;
}

void write_binary_file(City cities[], int size, char* filename){
    ofstream stream(filename, ios::out | ios::binary);
    if(stream.fail()){
        cerr << "failed to open file: " << filename << endl;
        exit(1);
    }
    
    for(int i =0; i < size; i++)
        stream.write((char*)&cities[i], sizeof(City));
    stream.close();
}

void print_from_binary(char* filename) {
    //opening the binary file
    ifstream input(filename, ios::in | ios::binary);
    if (input.fail()) {
        cerr << "failed to open file: " << filename << endl;
        exit(1);
    }
    //creating the output filename and changing the extension
    string fileNameTxt;
    int i = 0;
    while (filename[i] != '.') {
        fileNameTxt.push_back(filename[i]);
        i++;
    }
    fileNameTxt.append(".txt");

    //creating the output file
    ofstream output(fileNameTxt);
    if (output.fail()) {
        cerr << "failed to create file: " << "cities.txt" << endl;
        exit(1);
    }
    
    City cities[size];

    //reading and displaying each object as well as saving each object to the output file
    for (int i = 0; i < size; i++) {
        input.read((char*)(&cities[i]), sizeof(cities));

        cout << "Name: " << cities[i].name << ", x coordinate: " << cities[i].x
                << ", y coordinate: " << cities[i].y << endl;

        output << "Name: " << cities[i].name << ", x coordinate: " << cities[i].x
                << ", y coordinate: " << cities[i].y << endl;
    }

    input.close();
    output.close();
}




