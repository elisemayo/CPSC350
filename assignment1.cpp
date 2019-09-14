/*Author: Elise May
  Student ID: 2271041
  Email: may137@mail.chapman.edu
  CPSC 350-02
  Assignment 1
  This program calculates basic statistics for a given list of DNA strings.
*/

#include "assignment1.h"
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

assignment1(){
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
}

~assignment1(){}

//reading DNA string from file
void assignment1::readFile(instream & ifstream){
  ifstream filein(fileName); //open the file

  if (fileName.is_open() && fileName.good()) {
      string DNAstring = "";
      while (!instream.eof()){
        getline(fileName, DNAstring, ' ');
      }

  } else {
      cout << "Failed to open file.";
  }
  inputFile.close();
  return 0;
}

void assignment1::statCalc(outstream){
//calculating basic stats (sum, mean, variance, standard deviation)
  for(int i = 0; i < DNAstring.length(); ++i){
    toupper(DNAstring[i]);
    switch(DNAstring[i]){
      case('A'): {
        countA++;
        sum++;
        break;
      }
      case('C'): {
        countC++;
        sum++;
        break;
      }
      case('T'): {
        countT++;
        sum++;
        break;
      }
      case('G'): {
        countG++;
        sum++;
        break;
      }
    }
    lineCount++;
  }
  mean = (double)sum / (double)lineCount;
  variance += pow(mean - DNAstring.length());
  variance /= lineCount;
  stdev = sqrt(variance);

  outstream << "Sum: " << sum << endl;
  outstream << "Mean: " << mean << endl;
  outstream << "Variance: " << variance << endl;
  outstream << "Standard Deviation: " << stdev << endl;

//calculating the relative probabilities of each nucleotide
  relativeProbA = countA / sum;
  relativeProbC = countC / sum;
  relativeProbT = countT / sum;
  relativeProbG = countG / sum;

  outstream << "Relative Probability of A: " << relativeProbA << endl;
  outstream << "Relative Probability of C: " << relativeProbC << endl;
  outstream << "Relative Probability of T: " << relativeProbT << endl;
  outstream << "Relative Probability of G: " << relativeProbG << endl;

  for(int i = 0; i < DNAstring.length(); ++i){
    toupper(DNAstring[i]);
    switch(DNAstring[i]){
      case('A'): {
        if(DNAstring[i + 1] == 'A'){
          countAA++;
          bigramTotal++;
        }
        else if(DNAstring[i + 1] == 'C'){
          countAC++;
          bigramTotal++;
        }
        else if(DNAstring[i + 1] == 'T'){
          countAT++;
          bigramTotal++;
        }
        else if(DNAstring[i + 1] == 'G'){
          countAG++;
          bigramTotal++;
        }
        break;
      }
      case('C'): {
        if(DNAstring[i + 1] == 'A'){
          countCA++;
          bigramTotal++;
        }
        else if(DNAstring[i + 1] == 'C'){
          countCC++;
          bigramTotal++;
        }
        else if(DNAstring[i + 1] == 'T'){
          countCT++;
          bigramTotal++;
        }
        else if(DNAstring[i + 1] == 'G'){
          countCG++;
          bigramTotal++;
        }
        break;
      }
      case('T'): {
        if(DNAstring[i + 1] == 'A'){
          countTA++;
          bigramTotal++;
        }
        else if(DNAstring[i + 1] == 'C'){
          countTC++;
          bigramTotal++;
        }
        else if(DNAstring[i + 1] == 'T'){
          countTT++;
          bigramTotal++;
        }
        else if(DNAstring[i + 1] == 'G'){
          countTG++;
          bigramTotal++;
        }
        break;
      }
      case('G'): {
        if(DNAstring[i + 1] == 'A'){
          countGA++;
          bigramTotal++;
        }
        else if(DNAstring[i + 1] == 'C'){
          countGC++;
          bigramTotal++;
        }
        else if(DNAstring[i + 1] == 'T'){
          countGT++;
          bigramTotal++;
        }
        else if(DNAstring[i + 1] == 'G'){
          countGG++;
          bigramTotal++;
        }
        break;
      }
    }
  }

  relativeProbAA = countAA / bigramTotal;
  relativeProbAC = countAC / bigramTotal;
  relativeProbAT = countAT / bigramTotal;
  relativeProbAG = countAG / bigramTotal;
  relativeProbCA = countCA / bigramTotal;
  relativeProbCC = countCC / bigramTotal;
  relativeProbCT = countCT / bigramTotal;
  relativeProbCG = countCG / bigramTotal;
  relativeProbTA = countTA / bigramTotal;
  relativeProbTC = countTC / bigramTotal;
  relativeProbTT = countTT / bigramTotal;
  relativeProbTG = countTG / bigramTotal;
  relativeProbGA = countGA / bigramTotal;
  relativeProbGC = countGC / bigramTotal;
  relativeProbGT = countGT / bigramTotal;
  relativeProbGG = countGG / bigramTotal;

  outstream << "Relative Probability of Nucleotide Bigrams:" << endl;
  outstream << "AA: " << relativeProbAA << endl;
  outstream << "AC: " << relativeProbAC << endl;
  outstream << "AT: " << relativeProbAT << endl;
  outstream << "AG: " << relativeProbAG << endl;
  outstream << "CA: " << relativeProbCA << endl;
  outstream << "CC: " << relativeProbCC << endl;
  outstream << "CT: " << relativeProbCT << endl;
  outstream << "CG: " << relativeProbCG << endl;
  outstream << "TA: " << relativeProbTA << endl;
  outstream << "TC: " << relativeProbTC << endl;
  outstream << "TT: " << relativeProbTT << endl;
  outstream << "TG: " << relativeProbTG << endl;
  outstream << "GA: " << relativeProbGA << endl;
  outstream << "GC: " << relativeProbGC << endl;
  outstream << "GT: " << relativeProbGT << endl;
  outstream << "GG: " << relativeProbGG << endl;
}

//calculating the gaussian distribution
void assignment1::gaussianDist(outstream){
  double a = (double)rand() / (double)(RAND_MAX);
  double b = (double)rand() / (double)(RAND_MAX);
  double c = sqrt(-2 * log(a)) * (cos(2 * M_PI * b));
  double d = (stdev * c) + mean;

//iterating 1000 times
  for(int i = 0; i < 1000; ++i){
    for(int j = 0; j < d; ++j){
      //generating random probability
      randProb = (double)rand() % 100

      if(randProb <= relativeprobA){
        outstream << "A";
      }
      else if(randProb <= (relativeProbA + relativeProbC)){
        outstream << "C";
      }
      else if(randProb <= (relativeProbA + relativeProbC + relativeProbT)){
        outstream << "T";
      }
      else if(randProb <= (relativeProbA + relativeProbC + relativeProbT + relativeProbG)){
        outstream << "G";
      }
    }
    outstream << endl;
  }
}
