/*
Elise May
Student ID: 2271041
Email: may137@mail.chapman.edu
CPSC 350-02
Assignment 4
*/
#include <iostream>

using namespace std;

class Student{
  public:
    Student();
    Student(int t, int e);
    ~Student();

    int windowTime;
    int idleTime;
    int entryTime;
    int queueTime;
};
