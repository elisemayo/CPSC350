/*
Elise May
Student ID: 2271041
Email: may137@mail.chapman.edu
CPSC 350-02
Assignment 5
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
    ListNode(T d);
    ~ListNode();
};

//implementation
//constructor
template <class T>
ListNode<T>::ListNode(){
  next = NULL;
  prev = NULL;
}

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
