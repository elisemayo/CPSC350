/*
Elise May
Student ID: 2271041
Email: may137@mail.chapman.edu
CPSC 350-02
Assignment 5
*/
#include "ListNode.h"
#include <iostream>

using namespace std;

template <class T>
class DoublyLinkedList{
  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    //pointers and variables
    ListNode<T> * front;
    ListNode<T> * back;
    unsigned int size;

    //core functions
    void insertBack(T d);
    void insertFront(T d);
    T removeBack();
    T removeFront();
    T peekBack();
    T peekFront();
    bool search(T d);
    bool remove(T d);

    //aux functions
    bool isEmpty();
    unsigned int getSize();
};

//implementation
//constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

//destructor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  ListNode<T> * temp = front;

  while(front -> next != NULL){
    temp = front -> next;
    front -> next = NULL;
    temp -> prev = NULL;
    delete front;
    front = temp;
  }
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  ListNode<T> * node = new ListNode<T>(d);

  if(isEmpty()){
    //we have empty list
    front = node;
  }
  else{
    //not an empty list
    back -> next = node;
    node -> prev = back;
  }
  back = node;
  ++size;
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d){
  ListNode<T> * node = new ListNode<T>(d);

  if(isEmpty()){
    //we have empty list
    back = node;
  }
  else{
    //not an empty list
    front -> prev = node;
    node -> next = front;
  }
  front = node;
  ++size;
}

template <class T>
T DoublyLinkedList<T>::removeBack(){
  if(!isEmpty()){
  //placeholder
  ListNode<T> * bk = back;

  if(back -> prev == NULL){
    //only one element in list
    front = NULL;
    back = NULL;
  }
  else{
    //more than one element in list
    back -> prev -> next = NULL;
  }

  back = back -> prev;
  T temp = bk -> data;
  bk -> prev = NULL;
  --size;
  delete bk;
  return temp;
  }
  else{
    return T();
  }
}

template <class T>
T DoublyLinkedList<T>::removeFront(){
  if(!isEmpty()){
  //placeholder
  ListNode<T> * ft = front;

  if(front -> next == NULL){
    //only one element in list
    front = NULL;
    back = NULL;
  }
  else{
    //more than one element in list
    front -> next -> prev = NULL;
  }

  front = front -> next;
  T temp = ft -> data;
  ft -> next = NULL;
  --size;
  delete ft;
  return temp;
  }
  else{
    return T();
  }
}

template <class T>
T DoublyLinkedList<T>::peekBack(){
  return back -> data;
}

template <class T>
T DoublyLinkedList<T>::peekFront(){
  return front -> data;
}

template <class T>
bool DoublyLinkedList<T>::search(T d){
  ListNode<T> * node = front;

  while(node != NULL){
    if(node -> data == d){
      //found
      return true;
    }
    else{
      node = node -> next;
    }
  }
  //not found
  return false;
}

template <class T>
bool DoublyLinkedList<T>::remove(T d){
  ListNode<T> * current = front;

  while(current != NULL){
    //found node to remove
    if (current -> data == d){
      if(current == front){
        removeFront();
        return true;
      }
      else if(current == back){
        removeBack();
        return true;
      }
      //somewhere in the middle
      else{
        current -> prev -> next = current -> next;
        current -> next -> prev = current -> prev;
        delete current;
        --size;
        return true;
      }
    }
    current = current -> next;
  }
  return false;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  return(size == 0);
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}
