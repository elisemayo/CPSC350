/*
 Elise May
 Student ID: 2271041
 Email: may137@mail.chapman.edu
 CPSC 350-02
 Assignment 5
*/
#include "Student.h"

using namespace std;

//constructor
Student::Student(){}

//overloaded constructor
Student::Student(int id, string name, string level, string major, double gpa, int advisor){
  ID = id;
  name = name;
  level = level;
  major = major;
  GPA = gpa;
  advisor = advisor;
}

//destructor
Student::~Student(){}

double Student::getGPA(){
  return GPA;
}

string Student::getMajor(){
  return major;
}

void Student::setAdvisor(int advisorID){
  advisor = advisorID;
}

int Student::getAdvisor(){
  return advisor;
}

void Student::printStudent(){
  cout << "Name: " << name << endl;
  cout << "Student ID: " << ID << endl;
  cout << "Grade: " << level << endl;
  cout << "Major: " << major << endl;
  cout << "GPA: " << GPA << endl;
  cout << "Advisor ID: " << advisor << endl;
}
