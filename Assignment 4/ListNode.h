/*
Elise May
Student ID: 2271041
Email: may137@mail.chapman.edu
CPSC 350-02
Assignment 4
*/
#include <iostream>

using namespace std;

template <class T>

class ListNode{
  public:
    T data;
    ListNode<T> * next;
    ListNode<T> * prev;

    ListNode();
    ListNode(T data);
    ~ListNode();
};

//implementation
//constructor
template <class T>
ListNode<T>::ListNode(){}

//overloaded constructor
template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

//destructor
template <class T>
ListNode<T>::~ListNode(){
  if(next != NULL){
      next = NULL;
      prev = NULL;
      delete next;
      delete prev;
  }
}
