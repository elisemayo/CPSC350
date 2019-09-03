#include "Quiz1.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char**argv)
{
//string test = argv[1];
string test = "eliseamay";
Quiz1 q;

cout << "number of command line arguments: " << argc << endl;
cout << "the number of vowels in " << test << " is: " << q.countVowels(test) << endl;
cout << "argv[0] is: " << argv[0] << endl;

cout << "program exited successfully" << endl;
