/*
 Elise May
 Student ID: 2271041
 Email: may137@mail.chapman.edu
 CPSC 350-02
 Assignment 5
*/
#include "Student.h"
// #include "Faculty.h"
#include "BST.h"
// #include "Menu.h"

using namespace std;

int main(int argc, char const *argv[]) {
  // Menu m;
  // m.menuSelect();

  //BST test
  cout << "--------------- BST ----------------" << endl;
  BST<int> * tree = new BST<int>();
  tree -> insert(20);
  tree -> insert(8);
  tree -> insert(25);
  tree -> printTree();
  tree -> printNode(20);
  tree -> deleteNode(8);
  tree -> printTree();

  //person test
  cout << "--------------- Person ----------------" << endl;
  Person * p = new Person();
  p -> ID = 345093;
  p -> name = "Elise";
  p -> level = "Senior";
  cout << p -> getID() << endl;
  p -> setID(2051);
  cout << p -> getID() << endl;
  cout << p -> getName() << endl;
  cout << p -> getLevel() << endl;

  //student test
  cout << "--------------- Student ----------------" << endl;
  Student * s = new Student();
  s -> ID = 345093;
  s -> name = "Elise";
  s -> level = "Senior";
  s -> major = "Bidniss";
  s -> GPA = 4.0;
  s -> advisor = 230948;
  cout << s -> getAdvisor() << endl;
  s -> setAdvisor(2051);
  cout << s -> getGPA() << endl;
  cout << s -> getMajor() << endl;
  cout << s -> getAdvisor() << endl;
  s -> printStudent();

  // //DLL test
  // cout << "--------------- DLL ----------------" << endl;
  // DoublyLinkedList<int>* dll = new DoublyLinkedList<int>();
  //
  // dll -> insertFront(10);
  // dll -> printList();
  // dll -> insertBack(12);
  // dll -> printList();
  // dll -> insertBack(9);
  // dll -> printList();
  // dll -> insertBack(10);
  // dll -> printList();
  // dll -> insertBack(11);
  // dll -> printList();
  // dll -> removeBack();
  // dll -> printList();
  //
  // //faculty test
  // cout << "--------------- Faculty ----------------" << endl;
  // Faculty * f = new Faculty();
  // f -> ID = 345093;
  // f -> name = "Elise";
  // f -> level = "Exec";
  // f -> dept = "Bidniss";
  // cout << f -> getDept() << endl;
  // f -> printFaculty();

  return 0;
}
