/*
Elise May
Student ID: 2271041
Email: may137@mail.chapman.edu
CPSC 350-02
Assignment 4
*/
#include "Simulation.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
  Simulation s;

  if(argc >= 2){
    string file = argv[1];
    int currentTime = 0;
    int openWindows = 0;
    bool isRunning = true;

    if(s.readFile(file)){
      while(isRunning){
        if(s.studentQueue.isEmpty()){
          int count = 0;

          for(int i = 0; i < s.totalWindows; ++i){
            //open window
            if((s.windowArray[i] -> windowTime) < 1){
              count++;
            }
          }
          //break statement
          if(count == s.totalWindows){
            isRunning = false;
          }
        }
        //check each window, move to window if needed
        for(int i = 0; i < s.totalWindows; ++i){
          //check if window open
          if(s.windowArray[i] -> windowTime < 1){
            //someone in line
            if(!s.studentQueue.isEmpty()){
              Student* student = s.studentQueue.Front();
              //student ready for window
              if(student -> entryTime <= currentTime){
                //update idle stats with idle times
                if(s.windowArray[i] -> idleTime > 0){
                  s.idleTimeStats.insert(s.windowArray[i] -> idleTime);
                }
                //moving from queue to window
                s.windowArray[i] = s.studentQueue.remove();
                //update waiting stats
                s.waitTimeStats.insert(s.windowArray[i] -> queueTime);
                }
             }
           }
         }
         //update timer
         currentTime++;
         s.timer(currentTime);
      }
      //account for windows that remain idle
      for(int i = 0; i < s.totalWindows; ++i){
        if(s.windowArray[i] -> idleTime > 0){
          s.idleTimeStats.insert(s.windowArray[i] -> idleTime);
        }
      }
      //output
      cout << "Mean Student Wait Time: " << s.meanTime() << endl;
      cout << "Median Student Wait Time: " << s.medianTime() << endl;
      cout << "Longest Student Wait Time: " << s.longestTime() << endl;
      cout << "Students Waiting Over Ten Minutes: " << s.overTenTime() << endl;
      cout << "Mean Window Idle Time: " << s.meanIdleTime() << endl;
      cout << "Longest Window Idle Time: " << s.longestIdleTime() << endl;
      cout << "Idle Time Over Five Minutes: " << s.idleOverFiveTime() << endl;
    }
  }
  //check for file input name
  else{
    cout << "ERROR! Enter a valid file name idiot!" << endl;
  }
  return 0;
}
