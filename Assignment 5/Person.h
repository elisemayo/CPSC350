/*
 Elise May
 Student ID: 2271041
 Email: may137@mail.chapman.edu
 CPSC 350-02
 Assignment 5
 */
 #ifndef PERSON_H
 #define PERSON_H
 #include <iostream>

 using namespace std;

 class Person{
  public:
   //variables
   int ID;
   string name;
   string level;

   //constructor
   Person();
   //overloaded constructor
   //Person(int id, string name, string level);
   //destructor
   ~Person();

   //methods
   int getID();
   void setID(int value);

   string getName();
   string getLevel();
 };

#endif
