/*
 Elise May
 Student ID: 2271041
 Email: may137@mail.chapman.edu
 CPSC 350-02
 Assignment 5
 */
#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

template <class T>
class GenStack{
  public:
    GenStack();
    ~GenStack();

    void push(T d);
    T pop();
    T peek(); //aka top()

    bool isEmpty();

    T * rollback;
};

//implementation
template <class T>
GenStack<T>::GenStack(){
  rollback = new DoublyLinkedList<T>();
}

template <class T>
GenStack<T>::~GenStack(){ //destructor
  delete rollback;
}

//add to the stack
template <class T>
void GenStack<T>::push(T d){
  rollback -> insertFront(d);
}

//return and remove from stack
template <class T>
T GenStack<T>::pop(){
  return rollback -> removeFront();
}

//returns but does not remove from stack
template <class T>
T GenStack<T>::peek(){
  if(isEmpty()){
    cout << "Cannot undo..." << endl;
    return 0;
  }
  else{
    return rollback -> peekFront();
  }
}

//check if stack is empty
template <class T>
bool GenStack<T>::isEmpty(){
  return rollback -> isEmpty();
}
