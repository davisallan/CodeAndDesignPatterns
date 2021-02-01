/*
* File Name: DynString.cpp
* Lab # and Assignment #: Lab 4 Exercise A
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: 2020-10-18
*/

#include "MyArray.h"
#include <assert.h>

MyArray::MyArray(): sizeM(0) {
    storageM = new EType[0];
    assert(storageM != NULL);
}

MyArray::MyArray(const EType *builtin, int sizeA): sizeM(sizeA){
    storageM = new EType[sizeA];
    assert(storageM != NULL);

    for (int i = 0; i < sizeA; i++) {
        storageM[i] = builtin[i];
    }   
}

MyArray::MyArray(const MyArray& source) : sizeM(source.size()){ 
    storageM = new EType[sizeM];
    assert(storageM != NULL);

    for (int i = 0; i < sizeM; i++) {
    storageM[i] = source.storageM[i];
    }
}

MyArray& MyArray::operator = (const MyArray& rhs) { 
    if (this != &rhs) {
        delete [] storageM;
        sizeM = rhs.size();
        storageM = new EType[sizeM];
        assert(storageM != NULL);

        for (int i = 0; i < sizeM; i++) {
            storageM[i] = rhs.storageM[i];
        }
    }
    return *this;
}

MyArray::~MyArray() { 
    delete [] storageM;
    storageM = NULL;
}

int MyArray::size() const {
    return sizeM;
}

EType MyArray::at(int i) const {
    assert(i >= 0 && i < size());
    return storageM[i];
}

void MyArray::set(int i, EType new_value) {
    assert(i >= 0 && i < size());
    storageM[i] = new_value;
}

void MyArray::resize(int new_size) {
    assert(new_size >= 0);
    EType *resized = new EType[new_size];
    assert(resized != NULL);

    if (new_size > sizeM) {
        for (int i = 0; i < sizeM; i++) {
            resized[i] = storageM[i];
        }
    }
    else {
    for (int i = 0; i < new_size; i++) {
            resized[i] = storageM[i];
        }
    }
    
    delete [] storageM;
    storageM = resized;
    sizeM = new_size;
}