/*
Elise May
Student ID: 2271041
Student Email: may137@mail.chapman.edu
CPSC 350-02
Assignment 6
*/
#include "Sorting.h"

using namespace std;

Sorting::Sorting(){}

Sorting::~Sorting(){
  delete[] bubbleSortArray;
  delete[] selectionSortArray;
  delete[] insertionSortArray;
  delete[] quickSortArray;
  delete[] mergeSortArray;
}

void Sorting::bubbleSort(double array[]){
  for(int i = 0; i < numElements; ++i){
    int tmp = 0;
    for(int j = 0; j < numElements - 1; ++j){
      if(array[j] > array[j + 1]){
        tmp = array[j + 1];
        array[j + 1] = array[j];
        array[j] = tmp;
      }
    }
  }
}

void Sorting::selectionSort(double array[], int size){
  int i, j, minIndex, tmp;
  for(i = 0; i < size - 1; i++){
    minIndex = i;
    for(j = i + 1; j < size; j++){
      if(array[j] < array[minIndex]){
        minIndex = j;
      }
      if(minIndex != i){ //swap
        tmp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = tmp;
      }
    }
  }
}

void Sorting::insertionSort(double array[]){
  //marker
  for(int i = 1; i < numElements; ++i){
    //store marked item
    double tmp = array[i];
    //where to start shifting
    int mark = i;
    //while element to left is larger, shift
    while(mark > 0 && array[i - 1] >= tmp){
      array[i] = array[i - 1];
      --mark;
    }
    //put marked item in correct spot
    array[mark] = tmp;
  }
}

int Sorting::partition(double array[], int low, int high){
  int pivot = array[(low + high) / 2];

  while(low <= high){
    while(array[low] < pivot){
      low++;
    }
    while(array[high] > pivot){
      high--;
    }

    if(low <= high){ //swap
      double tmp = array[low];
      array[low] = array[high];
      array[high] = tmp;
      low++;
      high--;
    }
  }
  return low;
}

void Sorting::quickSort(double array[], int low, int high){
  int mark = partition(array, low, high);

  if(low < mark - 1){
    quickSort(array, low, mark - 1);
  }
  if(high > mark){
    quickSort(array, mark, high);
  }
}

void Sorting::merge(double array[], int low, int high, int mid){
  int i, j, k, tmp[high - low + 1];
  i = low;
  k = 0;
  j = mid + 1;

  //merge two halves into temp array
  while(i <= mid && j <= high){
    if(array[i] < array[j]){
      tmp[k] = array[i];
      k++;
      i++;
    }
    else{
      tmp[k] = array[j];
      k++;
      j++;
    }
  }
  //insert values i to mid into temp array
  while(i <= mid){
    tmp[k] = array[i];
    k++;
    i++;
  }
  //insert values j to high into temp array
  while(j <= high){
    tmp[k] = array[j];
    k++;
    j++;
  }
  //copy sorted data from temp array to array
  for(i = low; i <= high; i++){
    array[i] = tmp[i - low];
  }
}

void Sorting::mergeSort(double array[], int low, int high){
  int mid;

  if(low < high){
    mid = (low + high)/2;
    //split data in half
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);
    //merge again
    merge(array, low, high, mid);
  }
}

void Sorting::sortAll(){
  clock_t timeStart;
  clock_t timeEnd;
  float runTime;

  cout << "---Sorting in Process---" << endl;
  cout << "------------------------" << endl;
  cout << "--------RunTimes--------" << endl;

  //bubbleSort
  timeStart = clock();
  bubbleSort(bubbleSortArray);
  timeEnd = clock();
  runTime = (float(timeEnd - timeStart) / CLOCKS_PER_SEC) * 1000;
  cout << "-------Bubble Sort------" << endl;
  cout << "Start: " << timeStart << endl;
  cout << "End: " << timeEnd << endl;
  cout << "RunTime: " << runTime << " ms" << endl;

  //selectionSort
  timeStart = clock();
  selectionSort(selectionSortArray, numElements);
  timeEnd = clock();
  runTime = (float(timeEnd - timeStart) / CLOCKS_PER_SEC) * 1000;
  cout << "-----Selection Sort-----" << endl;
  cout << "Start: " << timeStart << endl;
  cout << "End: " << timeEnd << endl;
  cout << "RunTime: " << runTime << " ms" << endl;

  //insertionSort
  timeStart = clock();
  insertionSort(insertionSortArray);
  timeEnd = clock();
  runTime = (float(timeEnd - timeStart) / CLOCKS_PER_SEC) * 1000;
  cout << "-----Insertion Sort-----" << endl;
  cout << "Start: " << timeStart << endl;
  cout << "End: " << timeEnd << endl;
  cout << "RunTime: " << runTime << " ms" << endl;

  //quickSort
  timeStart = clock();
  quickSort(quickSortArray, 0, numElements - 1);
  timeEnd = clock();
  runTime = (float(timeEnd - timeStart) / CLOCKS_PER_SEC) * 1000;
  cout << "-------Quick Sort-------" << endl;
  cout << "Start: " << timeStart << endl;
  cout << "End: " << timeEnd << endl;
  cout << "RunTime: " << runTime << " ms" << endl;

  //mergeSort
  timeStart = clock();
  mergeSort(mergeSortArray, 0, numElements - 1);
  timeEnd = clock();
  runTime = (float(timeEnd - timeStart) / CLOCKS_PER_SEC) * 1000;
  cout << "-------Merge Sort-------" << endl;
  cout << "Start: " << timeStart << endl;
  cout << "End: " << timeEnd << endl;
  cout << "RunTime: " << runTime << " ms" << endl;

  cout << "----Sorting Complete----" << endl;
}

void Sorting::writeFile(string file){
  int items;
  double randNum;

  cout << "Please enter the number of items you would like to sort: " << endl;
  cin >> items;

  ofstream outputFile;
  outputFile.open(file);

  if(outputFile.is_open()){
    outputFile << items << "\n";
    for(int i = 0; i < items; ++i){
      randNum = rand()%10000;
      outputFile << randNum << "\n";
    }
    outputFile.close();
  }
  else{
    cout << "File could not be opened..." << endl;
  }
}

void Sorting::readFile(string file){
  string numberElements;
  string line;
  double size;
  int numLine = 1;

  //read in and convert types
  ifstream inputFile;
  inputFile.open(file.c_str());
  getline(inputFile, numberElements);
  numElements = atoi(numberElements.c_str());

  //create new arrays to be sorted
  bubbleSortArray = new double [numElements];
  selectionSortArray = new double [numElements];
  insertionSortArray = new double [numElements];
  quickSortArray = new double [numElements];
  mergeSortArray = new double [numElements];

  for(int i = 0; i < numElements; ++i){
    numLine++;
    getline(inputFile, line);

    try{
      size = atof(line.c_str());
    }
    catch(exception e){
      cout << "----Invalid File Format----" << endl;
      return;
    }
    //populate arrays with values
    bubbleSortArray[i] = size;
    selectionSortArray[i] = size;
    insertionSortArray[i] = size;
    quickSortArray[i] = size;
    mergeSortArray[i] = size;
  }
  inputFile.close();
  sortAll();
}
