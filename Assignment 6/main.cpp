/*
Elise May
Student ID: 2271041
Student Email: may137@mail.chapman.edu
CPSC 350-02
Assignment 6
*/
#include <iostream>
#include "Sorting.h"

using namespace std;

int main(int argc, char** argv){
  Sorting s;

  //error checking for if file was specified
  if(argc < 2){
    cout << "Error! Please enter file name..." << endl;
  }

  else if(argc >= 2){
    string file = argv[1];
    s.readFile(file);
  }
  return 0;
}
