/*
Elise May
Student ID: 2271041
Email: may137@mail.chapman.edu
CPSC 350-02
Assignment 4
*/
#include "Student.h"
#include "GenQueue.h"
#include <iostream>
#include <string>

using namespace std;

class Simulation{
  private:
    int lineType;
    int numStudents;
    int studentEntryTime;
    int studentWindowTime;
    int medianArrayCount;
    int idleArrayCount;

  public:
    Simulation();
    ~Simulation();

    //read in input text file
    bool readFile(string file);
    //keep track of time
    bool timer(int t);

    //output calculations
    double meanTime();
    double medianTime();
    int longestTime();
    int overTenTime();
    double meanIdleTime();
    int longestIdleTime();
    int idleOverFiveTime();

    //students at window array
    Student* *windowArray;
    //queue of students
    GenQueue<Student*> studentQueue;

    GenQueue<int> waitTimeStats;
    GenQueue<int> idleTimeStats;

    int *medianArray;
    int *idleArray;

    int totalStudents;
    int totalWindows;
};
