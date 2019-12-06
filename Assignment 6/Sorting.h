/*
Elise May
Student ID: 2271041
Student Email: may137@mail.chapman.edu
CPSC 350-02
Assignment 6
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

class Sorting{
  public:
    Sorting();
    ~Sorting();

    void bubbleSort(double array[]);
    void selectionSort(double array[], int size);
    void insertionSort(double array[]);
    int partition(double array[], int low, int high); //aux function for quickSort
    void quickSort(double array[], int low, int high);
    void merge(double array[], int low, int high, int mid); //aux funtion for mergeSort
    void mergeSort(double array[], int low, int high);

    void sortAll();

    void writeFile(string file);
    void readFile(string file);

  private:
    int numElements;
    double *bubbleSortArray;
    double *selectionSortArray;
    double *insertionSortArray;
    double *quickSortArray;
    double *mergeSortArray;
};
