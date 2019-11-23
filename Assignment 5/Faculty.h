/*
 Elise May
 Student ID: 2271041
 Email: may137@mail.chapman.edu
 CPSC 350-02
 Assignment 5
*/
#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include "Person.h"
#include "DoublyLinkedList.h"

using namespace std;

class Faculty: public Person{
  public:
    string dept;
    DoublyLinkedList<int> * advisees;

    //constructor
    Faculty();
    //overloaded constructor
    Faculty(int id, string name, string level, string dept);
    //destructor
    ~Faculty();

    //methods
    string getDept();
    int getNumAdvisees();

    void addAdvisee(int adviseeID);
    void removeAdvisee(int adviseeID);

    void printFaculty();

    bool operator == (const Faculty &f){
      return(this -> ID == f.ID);
    }

    bool operator != (const Faculty &f){
      return(this -> ID != f.ID);
    }

    bool operator <= (const Faculty &f){
      return(this -> ID <= f.ID);
    }

    bool operator >= (const Faculty &f){
      return(this -> ID >= f.ID);
    }

    bool operator < (const Faculty &f){
      return(this -> ID < f.ID);
    }

    bool operator > (const Faculty &f){
      return(this -> ID > f.ID);
    }
};

#endif
