/*Author: Elise May
  Student ID: 2271041
  Email: may137@mail.chapman.edu
  CPSC 350-02
  Assignment 1
  This program calculates basic statistics for a given list of DNA strings.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class assignment1
{
private:
  int countA = 0;
  int countC = 0;
  int countT = 0;
  int countG = 0;
  double sum = 0.0;
  int lineCount = 0;
  double mean = 0.0;
  double variance = 0.0;
  double stdev = 0.0;
  double relativeProbA = 0.0;
  double relativeProbC = 0.0;
  double relativeProbT = 0.0;
  double relativeProbG = 0.0;
  double countAA = 0.0;
  double countAC = 0.0;
  double countAT = 0.0;
  double countAG = 0.0;
  double countCA = 0.0;
  double countCC = 0.0;
  double countCT = 0.0;
  double countCG = 0.0;
  double countTA = 0.0;
  double countTC = 0.0;
  double countTT = 0.0;
  double countTG = 0.0;
  double countGA = 0.0;
  double countGT = 0.0;
  double countGC = 0.0;
  double countGG = 0.0;
  double bigramTotal = 0.0;
  double relativeProbAA = 0.0;
  double relativeProbAC = 0.0;
  double relativeProbAT = 0.0;
  double relativeProbAG = 0.0;
  double relativeProbCA = 0.0;
  double relativeProbCC = 0.0;
  double relativeProbCT = 0.0;
  double relativeProbCG = 0.0;
  double relativeProbTA = 0.0;
  double relativeProbTC = 0.0;
  double relativeProbTT = 0.0;
  double relativeProbTG = 0.0;
  double relativeProbGA = 0.0;
  double relativeProbGC = 0.0;
  double relativeProbGT = 0.0;
  double relativeProbGG = 0.0;
  double a = 0.0;
  double b = 0.0;
  double c = 0.0;
  double d = 0.0;
  double randProb = 0.0;

public:
  assignment1();
  ~assignment1();

  ifstream filein;
  ofstream fileout;

  void readFile(instream);
  void statCalc(outstream);
  void gaussianDist(outstream);
};
