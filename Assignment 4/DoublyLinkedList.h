/*
Elise May
Student ID: 2271041
Email: may137@mail.chapman.edu
CPSC 350-02
Assignment 4
*/
#include "ListNode.h"
#include <iostream>

using namespace std;

template <class T>
class DoublyLinkedList{
  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    //pointers
    ListNode<T> * front;
    ListNode<T> * back;
    unsigned int size;

    //core functions
    void insertBack(T data);
    T removeFront();
    T peek();
    void deletePos(int pos);

    //aux functions
    bool isEmpty();
    void printList();
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
DoublyLinkedList<T>::~DoublyLinkedList(){}

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
T DoublyLinkedList<T>::peek(){
  return front -> data;
}

template <class T>
void DoublyLinkedList<T>::deletePos(int pos){
  //index to keep track of where we are in list
  int idx = 0;
  //pointers
  ListNode<T> * curr = front;
  ListNode<T> * prev = front;

  //iterate through list until we find index of position we want to delete
  while(idx != pos){
    prev = curr;
    curr = curr -> next;
    ++idx;
  }
  //update pointers once index is found
  prev -> next = curr -> next;
  curr -> next -> prev = prev;
  curr -> next = NULL;
  curr -> prev = NULL;
  curr -> data = NULL;

  --size;
  delete curr;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  return(size == 0);
}

template <class T>
void DoublyLinkedList<T>::printList(){
  ListNode<T> * curr = front;

  while(true){
    if(curr -> next == NULL){
      break;
    }
  //print each element and iterate to next
  cout << curr -> data << endl;
  curr = curr -> next;
  }
}

template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}
