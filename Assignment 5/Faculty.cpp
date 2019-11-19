/*
 Elise May
 Student ID: 2271041
 Email: may137@mail.chapman.edu
 CPSC 350-02
 Assignment 5
*/
#include "Faculty.h"

using namespace std;

//constructor
Faculty::Faculty(){
  advisees = new DoublyLinkedList<int>();
}

//overloaded constructor
Faculty::Faculty(int id, string name, string level, string dept){
  ID = id;
  name = name;
  level = level;
  dept = dept;
  advisees = new DoublyLinkedList<int>();
}

//destructor
Faculty::~Faculty(){
  delete advisees;
}


string Faculty::getDept(){
  return dept;
}

int Faculty::getNumAdvisees(){
  return advisees -> getSize();
}

void Faculty::addAdvisee(int adviseeID){
  advisees -> insertBack(adviseeID);
}

void Faculty::removeAdvisee(int adviseeID){
  advisees -> remove(adviseeID);
}

void Faculty::printFaculty(){
  cout << "Name: " << name << endl;
  cout << "Faculty ID: " << ID << endl;
  cout << "Level: " << level << endl;
  cout << "Department: " << dept << endl;
  cout << "Advisee IDs: " << endl;
  advisees -> printList();
  cout << endl;
}
