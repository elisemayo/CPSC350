/*
 Elise May
 Student ID: 2271041
 Email: may137@mail.chapman.edu
 CPSC 350-02
 Assignment 5
*/
#include "Person.h"

using namespace std;

 //constructor
Person::Person(){}

 //destructor
Person::~Person(){}

int Person::getID(){
  return ID;
}

void Person::setID(int value){
  ID = value;
}

string Person::getName(){
  return name;
}

string Person::getLevel(){
  return level;
}
