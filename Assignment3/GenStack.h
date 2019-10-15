/*
 Elise May
 Student ID: 2271041
 Email: may137@mail.chapman.edu
 CPSC 350-02
 Assignment 3
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

template <class T>

class GenStack{
  public:
    GenStack();
    GenStack(int maxSize); //overloaded constructor
    ~GenStack();

    void push(T d);
    char pop();
    char peek(); //aka top()

    bool isFull();
    bool isEmpty();

    int size;
    int top;

    //pointers
    T *myArray;
    T *tempArray;
};

//implementation
template <class T>
GenStack<T>::GenStack(){} //default constructor

template <class T>
GenStack<T>::GenStack(int maxSize){ //overloaded constructor
  myArray = new T[maxSize];
  size = maxSize;
  top = -1;
  tempArray = new T[size];
}

template <class T>
GenStack<T>::~GenStack(){ //destructor
  delete myArray;
  delete tempArray;
  cout << "Stacks Destroyed! Program exiting. . ." << endl;
}

//add to the stack
template <class T>
void GenStack<T>::push(T d){
  if (isFull() == true){
    //create temporary array
    tempArray = new T[size];

    //copy original array to temp
    for (int i = 0; i < size; ++i){
      tempArray[i] = myArray[i];
    }

    //create a new array of double the length
    myArray = new T[size * 2];

    //copy temp array into new longer array
    for (int i = 0; i < size; ++i){
    	myArray[i] = tempArray[i];
  	}

    size *= 2;
  }
  else{
    myArray[++top] = d;
  }
}

//return and remove from stack
template <class T>
char GenStack<T>::pop(){
  if(isEmpty() == true){
    //cout << "Stack is empty..." << endl;
    return 0;
  }
  else{
    return myArray[top--];
  }
}

//returns but does not remove from stack
template <class T>
char GenStack<T>::peek(){
  if(isEmpty() == true){
    //cout << "Stack is empty..." << endl;
    return 0;
  }
  else{
    return myArray[top];
  }
}

//check if stack is full
template <class T>
bool GenStack<T>::isFull(){
  return (top == size - 1);
}

//check if stack is empty
template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}
