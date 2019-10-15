/*
 Elise May
 Student ID: 2271041
 Email: may137@mail.chapman.edu
 CPSC 350-02
 Assignment 3
 */

#include <iostream>
#include <stack>
#include <fstream>
#include <string>

using namespace std;

class delimiter{
  public:
    delimiter();
    ~delimiter();

    int checkMatch(string file);
};
