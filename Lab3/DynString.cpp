/*
* File Name: DynString.cpp
* Lab # and Assignment #: Lab 3 Exercise D
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: 
*/
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;
#include "DynString.h"

DynString::DynString(): lengthM(0), storageM(new char[1])
{
    storageM[0] = '\0';
}

DynString::DynString(const char *s): lengthM ((int)strlen(s))
{
    storageM = new char[lengthM + 1];
    strcpy(storageM, s);
    // Point 1
}

DynString::~DynString()
{
    delete [] storageM;
    // Point 2 
}

int DynString::length() const
{
    return lengthM;
}

char DynString::get_element(int pos)const
{
    assert(pos >= 0 && pos < length());
    return storageM[pos];;
}

void DynString::set_element(int pos, char value)
{
    assert(pos >= 0 && pos < length());
    storageM[pos] = value;
}

const char * DynString::c_str() const
{
    return storageM;
}

void DynString::truncate(int new_length)
{
    assert(new_length <= length());
    char *smaller_storage = new char[new_length + 1];
    assert(smaller_storage != NULL);
    
    for (int i = 0; i < new_length; i++)
        smaller_storage[i] = storageM[i];
    
    smaller_storage[new_length] = '\0';
    delete [] storageM;
    storageM = smaller_storage;
    lengthM = new_length;
    
}

void DynString::append(const DynString& tail)
{   
    //create new array of exact length required
    char *appended = new char[lengthM + tail.lengthM + 1];
    assert(appended != NULL);
    

    //if the string that is getting appended is empty, only copy tail
    if (storageM[0] == '\0') {
        for (int i = 0; i < tail.lengthM; i++){
            appended[i] = tail.storageM[i];
        }
    }
    else {
        int i = 0;    
        //copy original chars to new array
        for (int j = 0; j < lengthM; j++) {
            appended[j] = storageM[j];
            i++;
        }

        //append the tail characters
        for (int k = 0; k < tail.lengthM; k++) {
            appended[i] = tail.storageM[k];
            i++;
        }
    }
    //adjusting the new length
    lengthM += tail.lengthM;
    //setting the last character to null
    appended[lengthM] = '\0';
    
    delete [] storageM;
    storageM = appended;
}
