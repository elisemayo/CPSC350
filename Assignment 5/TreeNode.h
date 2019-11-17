/*
Elise May
Student ID: 2271041
Email: may137#mail.chapman.edu
CPSC 350-02
Assignment 5
*/
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class TreeNode{
  public:
    TreeNode();
    TreeNode(T k);
    ~TreeNode();

    T key;
    TreeNode<T> * left;
    TreeNode<T> * right;
};

template <class T>
TreeNode<T>::TreeNode(){
  key = NULL;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T k){
  key = k;
  left = NULL;
  right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode(){
  delete left;
  delete right;
}
