/*
Elise May
Student ID: 2271041
Email: may137@mail.chapman.edu
CPSC 350-02
Assignment 4
*/
#include "Student.h"
#include <iostream>

using namespace std;

//constructor
Student::Student(){
  windowTime = 0;
  idleTime = 0;
  entryTime = 0;
  queueTime = 0;
}

//overloaded constructor
Student::Student(int t, int e){
  windowTime = t;
  idleTime = 0;
  entryTime = e;
  queueTime = 0;
}

//destructor
Student::~Student(){}
