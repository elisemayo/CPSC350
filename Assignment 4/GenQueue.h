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

class GenQueue{
  public:
    GenQueue();
    ~GenQueue();

    //pointers
    ListNode<T> * front;
    ListNode<T> * rear;

    //core functions
    void insert(T d);
    T remove();

    //aux functions
    bool isEmpty();
    unsigned int getSize();
    void print();

    //variables
    T Front(); //head
    T Rear(); //tail
    unsigned int numElements;
};

//implementation
//constructor
template <class T>
GenQueue<T>::GenQueue(){
  front = NULL;
  rear = NULL;
  numElements = 0;
}

//destructor
template <class T>
GenQueue<T>::~GenQueue(){}

//insert node
template <class T>
void GenQueue<T>::insert(T d){
  ListNode<T> * node = new ListNode<T>(d);

  if(numElements == 0){
    front = node;
  }
  else{
    rear -> next = node;
    node -> prev = rear;
  }

  rear = node;
  ++numElements;
}

//remove node
template <class T>
T GenQueue<T>::remove(){
  if(!isEmpty()){
    ListNode<T> * node = front;

    //temporarily store current element
    T temp = node -> data;

    //check if only node in queue
    if(front -> next == NULL){
      front = NULL;
      rear = NULL;
    }

    //if more than one node in queue
    else{
      front -> next -> prev = NULL;
      front = front -> next;
    }
    //delete placeholder node
    delete node;
    --numElements;
    return temp;
  }
    //if it is an empty queue
  else{
      return T();
  }
}

//check if queue is empty
template <class T>
bool GenQueue<T>::isEmpty(){
  return (numElements == 0);
}

template <class T>
unsigned int GenQueue<T>::getSize(){
  return numElements;
}

template <class T>
void GenQueue<T>::print(){
  //initialize pointer to current node
  ListNode<T> * curr = front;

  //iterate through each node to print
  while(true){
    if(curr != NULL){
      cout << curr -> data << endl;
      curr = curr -> next;
    }
    else{
      break;
    }
  }
}

template <class T>
T GenQueue<T>::Front(){
  return front -> data;
}

template <class T>
T GenQueue<T>::Rear(){
  return rear -> data;
}
