/*
Elise May
Student ID: 2271041
Email: may137@mail.chapman.edu
CPSC 350-02
Assignment 4
*/
#include "Simulation.h"
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <algorithm> //using for sort function
#include <sstream>

using namespace std;

//constructor
Simulation::Simulation(){
  lineType = 1;
  studentEntryTime = 0;
  studentWindowTime = 0;
  numStudents = 0;
  medianArrayCount = 0;
  idleArrayCount = 0;
  totalWindows = 0;
  totalStudents = 0;
}

//destructor
Simulation::~Simulation(){
  delete [] windowArray;
  delete [] medianArray;
  delete [] idleArray;
}

bool Simulation::readFile(string file){
  string line;
  int lineNum = 1;

  ifstream inputStream;
  inputStream.open(file.c_str());

  if(inputStream.is_open()){
    try{
      getline(inputStream, line);
      totalWindows = atoi(line.c_str());

      for(int i = 0; i < totalWindows; ++i){
        Student* student = new Student();
        windowArray[i] = student;
      }
      lineNum++;
    }
    catch(exception e){
      cout << "ERROR! Cannot read input file..." << endl;
      return false;
    }

    while(getline(inputStream, line)){
      switch(lineType){
        //number of students
        case(1):{
          try{
            if(line != ""){
              numStudents = atoi(line.c_str());

              for(int i = 0; i < numStudents; ++i){
                getline(inputStream, line);
                lineNum++;
                try{
                  studentWindowTime = atoi(line.c_str());
                }
                catch(exception e){
                  cout << "ERROR! Cannot read student time at window..." << endl;
                  return false;
                }
                totalStudents++;

                Student* student = new Student(studentWindowTime, studentEntryTime);
                studentQueue.insert(student);
              }
              lineType--;
            }
          }
          catch(exception e){
            cout << "ERROR! Cannot read number of students..." << endl;
            return false;
          }
          break;
        }
        //clock ticks
        case(2):{
          try{
            studentEntryTime = atoi(line.c_str());
            lineType++;
            lineNum++;
          }
          catch(exception e){
            cout << "ERROR! Cannot read clock ticks..." << endl;
            return false;
          }
          break;
        }
        default:
          break;
      }
    }
  }
  else{
    cout << "ERROR! File could not be opened..." << endl;
    return false;
  }
  return true;
}

bool Simulation::timer(int t){
  for(int i = 0; i < totalWindows; ++i){
    if(windowArray[i] -> windowTime > 0){
      //decrease when student at window
      windowArray[i] -> windowTime--;
    }
    else{
      //increase when student not at window
      windowArray[i] -> idleTime++;
    }
  }

  if(!studentQueue.isEmpty()) {
    //set current to front of queue
    ListNode<Student*> *curr = studentQueue.front;
    //total time in queue
    while(curr != NULL){
      if(curr -> data -> entryTime < t){
        curr -> data -> queueTime += 1;
      }
      curr = curr -> next;
    }
  }
  return true;
}

double Simulation::meanTime(){
  //set current to front of queue
  ListNode<int> * curr = waitTimeStats.front;

  double total = 0;
  int counter = 0;
  double meanWait = 0;

  //count total of elements
  while(curr != NULL){
    total += curr -> data;
    curr = curr -> next;
    counter++;
  }
  //check if empty queue
  if(counter == 0){
    return 0;
  }

  meanWait = total / double(counter);

  return meanWait;
}

double Simulation::medianTime(){
  //set current to front of queue
  ListNode<int> * curr = waitTimeStats.front;

  medianArrayCount = 0;
  double medianWait = 0;

  //count number of elements in medianArray
  while (curr != NULL){
    curr = curr->next;
    medianArrayCount++;
  }
  //check if array empty
  if (medianArrayCount == 0){
    return 0;
  }
  else{
    //create new array of size counted
    medianArray = new int[medianArrayCount];
    //set current to back to front
    curr = waitTimeStats.front;

    //copy each element into new array
    for(int i = 0; i < medianArrayCount; ++i){
      medianArray[i] = curr -> data;
      curr = curr -> next;
    }
    //sort ascending
    sort(medianArray, medianArray + medianArrayCount);

    //if odd number of elements, use middle
    if (medianArrayCount % 2 == 1){
     double median = 0;
     int middle = 0;

     //find middle
     middle = (medianArrayCount / 2) + 1;
     median = medianArray[middle];

     return median;
    }
    //if even number of elements, use average of two middles
    else{
      double median = 0;
      int middle1 = 0;
      int middle2 = 0;

      //find two middles
      middle1 = medianArrayCount / 2;
      middle2 = (medianArrayCount / 2) + 1;
      //check if array is only 2 elements
      if(medianArray[middle2] == 0){
        return 0;
      }
      //calculate median of average
      median = double(medianArray[middle1]) / double(medianArray[middle2]);

      return median;
    }
  }
}

int Simulation::longestTime(){
  //if elements in array, return end of sorted array
  if (medianArrayCount != 0){
    return medianArray[medianArrayCount - 1];
  }
  else{
    return 0;
  }
}

int Simulation::overTenTime(){
  //if elements in array
  if(medianArrayCount != 0){
    int tenCount = 0;
    //iterate through and add to count if greater than 10
    for(int i = 0; i < medianArrayCount; ++i){
      if(medianArray[i] > 10){
        ++tenCount;
      }
    }
    return tenCount;
  }
  //if no elements in array
  else{
    return 0;
  }
}

double Simulation::meanIdleTime(){
  //set current to front of queue
  ListNode<int> * curr = idleTimeStats.front;
  //variables needed for calculations
  double total = 0;
  int count = 0;
  double meanIdle = 0;

  //counting to get total
  while(curr != NULL){
    total += curr -> data;
    curr = curr -> next;
    count++;
  }
  //empty queue
  if(count == 0){
    return 0;
  }

  meanIdle = total / double(count);

  return meanIdle;
}

int Simulation::longestIdleTime(){
  //set current to front of queue
  ListNode<int> * curr = idleTimeStats.front;
  idleArrayCount = 0;

  //counts the idle array
  while(curr != NULL){
    curr = curr -> next;
    idleArrayCount++;
  }

  //create new array of size of count
  idleArray = new int[idleArrayCount];

  //reset current to front
  curr = idleTimeStats.front;

  //iterate through to copy to idleArray
  for(int i = 0; i < idleArrayCount; ++i){
    idleArray[i] = curr -> data;
    curr = curr -> next;
  }
  //sort ascending
  sort(idleArray, idleArray + idleArrayCount);


  return idleArray[idleArrayCount - 1];
}

int Simulation::idleOverFiveTime(){
  int count = 0;

  for(int i = 0; i < idleArrayCount; ++i){
    if(idleArray[i] > 5){
      ++count;
    }
  }
  return count;
}
