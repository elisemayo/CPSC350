/*
 Elise May
 Student ID: 2271041
 Email: may137@mail.chapman.edu
 CPSC 350-02
 Assignment 5
*/
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Person.h"

using namespace std;

class Student: public Person{
  public:
    string major;
    double GPA;
    int advisor;

    //constructor
    Student();
    //overloaded constructor
    Student(int id, string name, string level, string major, double gpa, int advisor);
    //destructor
    ~Student();

    //methods
    double getGPA();
    string getMajor();
    void setAdvisor(int advisorID);
    int getAdvisor();
    void printStudent();
};

#endif
