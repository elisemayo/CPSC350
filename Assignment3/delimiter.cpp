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

delimiter::delimiter(){};
delimiter::~delimiter(){};

int delimiter::checkMatch(string file){
  bool validInput = true;

  GenStack<char> S(10);

  while(validInput = true){
    string line;
    int numLine = 1;

    ifstream inputFile;
    inputFile.open(file.c_str());

    //iterate through each line of code
    while(getline(inputFile, line)){
      for(int i = 0; i < line.size(); ++i){
        //checking for any delimiters
        if ((line[i] == '(') || (line[i] == ')') || (line[i] == '{') || (line[i] == '}') || (line[i] == '[') || (line[i] == ']')){
          //find matching brackets
         if((S.peek() == '(') && (line[i] == ')')){
           S.pop();
         }

         else if((S.peek() == '{') && (line[i] == '}')){
           S.pop();
         }

         else if((S.peek() == '[') && (line[i] == ']')){
           S.pop();
         }

         //find brackets that don't match
         else if((S.peek() == '(') && (line[i] == '}' || line[i] == ']')){
           cout << "Line " << numLine << ": expected ')' and found '" << line[i] << "'" << endl;
           return 0;
         }

         else if((S.peek() == '{') && (line[i] == ')' || line[i] == ']')){
           cout << "Line " << numLine << ": expected '}' and found '" << line[i] << "'" << endl;
           return 0;
         }

         else if((S.peek() == '[') && (line[i] == '}' || line[i] == ')')){
           cout << "Line " << numLine << ": expected ']' and found '" << line[i] << "'" << endl;
           return 0;
         }

         //check for missing closing brackets
         else if((line[i] == '(') || (line[i] == '{') || (line[i] == '[')){
            S.push(line[i]);
          }
        }
      }
      //go to next line
      ++numLine;
    }
    //if extra brackets, then exit program so user can fix errors
    if(S.isEmpty() == false){
      cout << "Reached end of file: Missing " << S.peek() << endl;
      return 0;
    }

    //if no syntax errors, then user has option to run another file
    else if(S.isEmpty() == true){
      char anuthaOne;

      cout << "Reached end of file: The delimiter syntax is correct." << endl;
      cout << "Would you like to analyze another file? Type 'y' or 'n'" << endl;
      cin >> anuthaOne;

      if((anuthaOne == 'Y')||(anuthaOne == 'y')){
        cout << "Please enter a file name: " << endl;
        cin >> file;

        checkMatch(file);
        break;
      }

      else{
        inputFile.close();
        validInput = false;
        return 0;
      }
    }
  }
  return 0;
}
