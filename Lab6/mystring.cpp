 /*
* File Name: myString.cpp
* Lab # and Assignment #: Lab 6 Exercise A and B  
* Lab section: B01
* Completed by: Davis Allan, 10016543
* Submission Date: Oct 30 2020
*/
#include "mystring.h"
#include <string.h>
#include <iostream>
using namespace std;

Mystring::Mystring()
{ 
  charsM = new char[1];

  // make sure memory is allocated.
  memory_check(charsM); 
  charsM[0] = '\0';
  lengthM = 0;
}

Mystring::Mystring(const char *s)
  : lengthM(strlen(s))
{
  charsM = new char[lengthM + 1];

 // make sure memory is allocated.
  memory_check(charsM);

  strcpy(charsM, s);
}

Mystring::Mystring(int n)
  : lengthM(0), charsM(new char[n])
{
  // make sure memory is allocated.
  memory_check(charsM);
  charsM[0] = '\0';
}

Mystring::Mystring(const Mystring& source):
  lengthM(source.lengthM), charsM(new char[source.lengthM+1])
{
  memory_check(charsM);
  strcpy (charsM, source.charsM);
}

Mystring::~Mystring()
{
  delete [] charsM;
}

int Mystring::length() const
{
  return lengthM;
}

char Mystring::get_char(int pos) const
{
  if(pos < 0 && pos >= length()){
    cerr << "\nERROR: get_char: the position is out of boundary." ;
  }

  return charsM[pos];
}

const char * Mystring::c_str() const
{
  return charsM;
}

void Mystring::set_char(int pos, char c)
{
  if(pos < 0 && pos >= length()){
    cerr << "\nset_char: the position is out of boundary."
	 << " Nothing was changed.";
    return;
  } 

  if (c != '\0'){
    cerr << "\nset_char: char c is empty."
	 << " Nothing was changed.";
    return;
  }

  charsM[pos] = c;
}

Mystring& Mystring::operator =(const Mystring& S)
{
  if(this == &S)
    return *this;
  delete [] charsM;
  lengthM = (int)strlen(S.charsM);
  charsM = new char [lengthM+1];
  memory_check(charsM);
  strcpy(charsM,S.charsM);

  return *this;
}

bool Mystring::operator>=(const Mystring& rhs) const {
  return strcmp(this->charsM, rhs.charsM) >= 0;
}

bool Mystring::operator<=(const Mystring& rhs) const {
  return strcmp(this->charsM, rhs.charsM) <= 0;
}

bool Mystring::operator!=(const Mystring& rhs) const {
  return strcmp(this->charsM, rhs.charsM) != 0;
}

bool Mystring::operator>(const Mystring& rhs) const {
  return strcmp(this->charsM, rhs.charsM) > 0;
}

bool Mystring::operator<(const Mystring& rhs) const {
  return strcmp(this->charsM, rhs.charsM) < 0;
}

bool Mystring::operator==(const Mystring& rhs) const {
  return strcmp(this->charsM, rhs.charsM) == 0;
}

char& Mystring::operator[](int i) const {
  if (i > this->lengthM) {
    cout << "Index out of bounds! Exiting program" << endl;
    exit(1);
  }
  return this->charsM[i];
}

ostream& operator<<(ostream& os, const Mystring& rhs) {
  os << rhs.charsM;
  return os;
}

Mystring& Mystring::append(const Mystring& other)
{
  char *tmp = new char [lengthM + other.lengthM + 1];
  memory_check(tmp);
  lengthM+=other.lengthM;
  strcpy(tmp, charsM);
  strcat(tmp, other.charsM);
  delete []charsM;
  charsM = tmp;

  return *this;
}

 void Mystring::set_str(char* s)
{
    delete []charsM;
    lengthM = (int)strlen(s);
    charsM=new char[lengthM+1];
    memory_check(charsM);

    strcpy(charsM, s);
}


void Mystring::memory_check(char* s)
{
  if(s == 0)
    {
      cerr <<"Memory not available.";
      exit(1);
    }
}











