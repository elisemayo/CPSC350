/*
 Elise May
 Student ID: 2271041
 Email: may137@mail.chapman.edu
 CPSC 350-02
 Assignment 3
 */

#include "GenStack.h"
#include "delimiter.h"
#include <iostream>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
  delimiter d;

  //check for command line input for file name
  if(argc >= 2) {
    string file = argv[1];
    d.checkMatch(file);
  }
  //exit if no command line argument provided
  else{
    cout << "Error: File not found." << endl;
    cout << "Please enter a valid file name." << endl;
  }
  return 0;
}
