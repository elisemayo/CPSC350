/*
Elise May
Student ID: 2271041
Email: may137#mail.chapman.edu
CPSC 350-02
Assignment 5
*/
#include <cstdlib>
#include <iostream>
#include "TreeNode.h"

using namespace std;

template <class T>
class BST{
  private:
    TreeNode<T> * root;

  public:
    BST();
    ~BST();

    bool search(T value); //checks to see if in tree
    T find(T value); //returns key if found
    void insert(T value); //insert a new record
    bool deleteNode(T value); //delete record
    TreeNode<T> * getSuccessor(TreeNode<T> * d); //helper method for delete
    bool isEmpty(); //checks if empty
    TreeNode<T> * getMax(); //traverse all the way to the right
    TreeNode<T> * getMin(); //traverse all the way to the left
    void recPrint(TreeNode<T> * node); //helper method for print
    void printTree(); //print whole Tree
    void printNode(T value); //print specified node
};

//implementation
template <class T>
BST<T>::BST(){
  root = NULL; //empty tree
}

template <class T>
BST<T>::~BST(){
  delete root;
}

template <class T>
bool BST<T>::search(T value){
  if(root == NULL) //empty Tree
    return false;
  else{
    //tree is not empty so find it
    TreeNode<T> * current = root;

    while(current -> key != value){
      if(value < current -> key)
        current = current -> left;
      else
        current = current -> right;

      if(current == NULL) //value does not exist
        return false;
    }
  }
  return true;
}

template <class T>
T BST<T>::find(T value){
  //empty tree
  if(root == NULL){
    return T();
  }
  else{
    TreeNode<T> * current = root;

    while(current -> key != value){
      if(value < current -> key){
        current = current -> left;
      }
      else{
        current = current -> right;
      }
      if(current == NULL){
        return T();
      }
    }
    return current -> key;
  }
}

template <class T>
void BST<T>::insert(T value){
  TreeNode<T> * node = new TreeNode<T>(value);
  if(root == NULL) //empty Tree
    root = node;
  else{ //not an empty tree
    //find where to insert
    TreeNode<T> * current = root;
    TreeNode<T> * parent = NULL;

    while(true){
      parent = current; //at root

      if(value < current -> key){
        //go left
        current = current -> left;

        if(current == NULL){ //found insertion point
          parent -> left = node;
          break;
        }
      }
      else{
        current = current -> right;

        if(current == NULL){ //found insertion point
          parent -> right = node;
          break;
        }
      }
    }
  }
}

template <class T>
bool BST<T>::deleteNode(T value){
  if(root == NULL) //empty tree
    return false;

  TreeNode<T> * current = root;
  TreeNode<T> * parent = root;
  bool isLeft = true;

  //if we make it here then tree is not empty so need to find the node
  while(current -> key != value){
    parent = current;
    if(value < current -> key){
      isLeft = true;
      current = current -> left;
    }
    else{
      isLeft = false;
      current = current -> right;
    }
    if(current == NULL) //value does not exist
      return false;
  }
  //now we found it
  //no children/leaf
  if(current -> left == NULL && current -> right == NULL){
    if(current == root)
      root = NULL;
    else if (isLeft)
      parent -> left = NULL;
    else
      parent -> right = NULL;
  }
  //node to be deleted has one child, we need to determine if child is left or right and proceed
  else if(current -> right == NULL){ //doesn't have right child must be a left child
    //check if node is root
    if(current == root)
      root = current -> left;
    else if(isLeft){
      parent -> left = current -> left;
    }
    else{
      //right child
      parent -> right = current -> left;
    }
  }

  else if(current -> left == NULL){ //doesn't have left child must be a right child
    //check if node is root
    if(current == root)
      root = current -> right;
    else if(isLeft){
      parent -> left = current -> right;
    }
    else{
      //right child
      parent -> right = current -> right;
    }
  }
  else{
    //node to be deleted has 2 children
    TreeNode<T> * successor = getSuccessor(current);

    if(current == root)
      root = successor;
    else if(isLeft)
      parent -> left = successor;
    else
      parent -> right = successor;

    successor -> left = current -> left;
  }
  return true;
}

template <class T>
TreeNode<T> * BST<T>::getSuccessor(TreeNode<T> * d){ //d is node to be deleted
  TreeNode<T> * current = d -> right;
  TreeNode<T> * sp = d;
  TreeNode<T> * successor = d;

  while(current != NULL){
    //traverse tree until find the successor
    sp = successor;
    successor = current;
    current = current -> left;
  }
  //by this point all of our pointers should be in right spot
  if(successor != d -> right){
    sp -> left = successor -> right;
    successor -> right = d -> right;
  }
  return successor;
}

template <class T>
bool BST<T>::isEmpty(){
  return(root == NULL);
}

template <class T>
TreeNode<T> * BST<T>::getMax(){
  TreeNode<T> * current = root;

  if(root == NULL) //check for empty Tree
    return NULL;

  while(current -> right != NULL){
    current = current -> right;
  }
  return current;
}

template <class T>
TreeNode<T> * BST<T>::getMin(){
  TreeNode<T> * current = root;

  if(root == NULL) //check for empty Tree
    return NULL;

  while(current -> left != NULL){
    current = current -> left;
  }
  return current;
}

template <class T>
void BST<T>::recPrint(TreeNode<T> * node){
  if(node == NULL)
    return;

  recPrint(node -> left);
  cout << node -> key << endl;
  recPrint(node -> right);
}

template <class T>
void BST<T>::printTree(){
  recPrint(root);
}

template <class T>
void BST<T>::printNode(T value){
  //empty tree
  if(root == NULL){
  cout << "No records found..." << endl;
  }
  else{
    TreeNode<T> * current = root;

    while(current -> key != value){
      if(value < current -> key){
        current = current -> left;
      }
      else{
        current = current -> right;
      }
      //node not found
      if(current == NULL){
        cout << "Record not found..." << endl;
      }
    }
    cout << current -> key;
  }
}
