/*Author: Elise May
  Student ID: 2271041
  Email: may137@mail.chapman.edu
  CPSC 350-02
  Assignment 1
  This program calculates basic statistics for a given list of DNA strings.
*/

#include "assignment1.h"
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char**argv[])
{
  ifstream filein;
  ofstream fileout;

//opening output file and printing header
  fileout.open("EliseMay.out");
  if(fileout.is_open() && fileout.good()){
    fileout << "Name: Elise May" << endl;
    fileout << "Student ID: 2271041" << endl;
    fileout << "Assignment 1" << endl;
  } else{
    cout << "File not found." << endl;
  }

//asking for input
int fileCheck = 0;
while(fileCheck = 0){
  string fileName;
  cout << "Enter file name: " << endl;
  cin >> fileName;

  filein.open(fileName.c_str());

  if(fileName.is_open() && fileName.good()){
  assignment1 a;
  a.readFile(filein);
  a.statCalc(fileout);
  a.gaussianDist(fileout);

  filein.close();

  //asking user if they'd like to repeat the process
  int repeat = 0
  while(repeat = 0){
    char ans;
    cout << "Would you like to process another list? Please enter 'Y' or 'N': " << endl;
    cin >> ans;
    if(ans == 'y' || ans == 'Y'){
      break;
    }
    else if(ans == 'n' || ans == 'N'){
      fileout.close();
      cout << "Program exited successfully." << endl;
      repeat++;
      return 0;
    }
    else{
      cout << "Answer not valid. Please enter 'Y' or 'N': " << endl;
      continue;
    }
  }
  fileCheck++;
  break;
} else {
    cout << "No file name entered. Try again." << endl;
    continue;
}
}
return 0;
}
