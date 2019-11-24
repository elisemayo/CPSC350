/*
//  Elise May
//  Student ID: 2271041
//  Email: may137@mail.chapman.edu
//  CPSC 350-02
//  Assignment 5
// */
// #include "Menu.h"
//
// using namespace std;
//
// Menu::Menu(){
//     struct stat buffer;
//
//     if(stat(studentTable.c_str(), &buffer) == 0){
//       studentTree.readFile(studentTable);
//     }
//
//     if(stat(facultyTable.c_str(), &buffer) == 0){
//       facultyTree.readFile(facultyTable);
//     }
// }
//
// Menu::~Menu(){}
//
// void menuSelect(){
//   int select;
//   bool b = true;
//
// cout << "~~~~~~~~~~~~~~~~~~~~~~~ Welcome ~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//
//   while(b){
//     cout << "~~~~~~~~~~~~~~~~~~~~~~~~ Menu ~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//     cout << 1 << ".  Print all student info by ascending ID." << endl;
//     cout << 2 << ".  Print all faculty info by ascending ID." << endl;
//     cout << 3 << ".  Print student info by student ID." << endl;
//     cout << 4 << ".  Print faculty info by faculty ID." << endl;
//     cout << 5 << ".  Print advisor info  by student ID." << endl;
//     cout << 6 << ".  Print advisee info by faculty ID." << endl;
//     cout << 7 << ".  Add new student." << endl;
//     cout << 8 << ".  Delete student by student ID." << endl;
//     cout << 9 << ".  Add new faculty." << endl;
//     cout << 10 << ". Delete faculty by faculty ID." << endl;
//     cout << 11 << ". Change advisor by student ID and faculty ID." << endl;
//     cout << 12 << ". Remove advisee by student ID and faculty ID." << endl;
//     cout << 13 << ". Undo" << endl;
//     cout << 14 << ". Exit" << endl;
//     cout << "Please Select a Menu Option: ";
//
//         cin >> select;
//
//         try{
//           int numSelect = atoi(select);
//
//           if(numSelect < 0 || numSelect > 14){
//             numSelect = 15;
//             cout << "Invalid Selection. Please enter a valid menu option." << endl;
//           }
//         }
//         catch(exception e){
//           numSelect = 15;
//           cout << "Error. Please enter a valid menu option." << endl;
//         }
//
//         switch(numSelect){
//           case 1:
//             printAllStudents();
//             break;
//           // case 2:
//           //   printAllFaculty();
//           //   break;
//           // case 3:
//           //   printStudent();
//           //   break;
//           // case 4:
//           //   printFaculty();
//           //   break;
//           // case 5:
//           //   printAdvisor();
//           //   break;
//           // case 6:
//           //   printAdvisees();
//           //   break;
//           // case 7:
//           //   addStudent();
//           //   break;
//           // case 8:
//           //   deleteStudent();
//           //   break;
//           // case 9:
//           //   addFaculty();
//           //   break;
//           // case 10:
//           //   deleteFaculty();
//           //   break;
//           // case 11:
//           //   changeAdvisor();
//           //   break;
//           // case 12:
//           //   removeAdvisee();
//           //   break;
//           // case 13:
//           //   rollback();
//           //   break;
//           case 14:
//             exit();
//             return;
//           default:
//             continue;
//         }
//     }
// }
// //
// // void Menu::rollback(){
// //   //will she ever make this work
// // }
//
// void Menu::exit(){
//   cout << "Exiting..." << endl;
// }
//
// // //aux methods
// void Menu::printAllStudents(){
//   if(studentTree -> isEmpty()){
//     cout << "No Student Records Found..." << endl;
//   }
//   else{
//     studentTree -> printTree();
//   }
// }
//
// void Menu::printAllFaculty(){
//   if(facultyTree -> isEmpty()){
//     cout << "No Faculty Records Found..." << endl;
//   }
//   else{
//     facultyTree -> printTree();
//   }
// }

// void Menu::printAdvisor(){
  // int studID = 0;
  //
  // if(studentTree -> isEmpty()){
  //   cout << "No student records found..." << endl;
  // }
  // else{
  //   cout << "Please Provide a Student ID: ";
  //   cin >> studID;
  //
  //   Student value = studentBST.search(studID);
  //
  //   if(value.id >= 0){
  //     Faculty fac = value.advisorID;
  //
  //     if(facultyTree.search(fac)){
  //       facultyTree.printNode(fac);
  //     }
  //     else{
  //       cout << "Advisor not found..." << endl;
  //     }
  //   }
  //   else{
  //     cout << "Student not found..." << endl;
  //   }
  // }
// }
//
// void Menu::printAdvisees(){
  // int facID = 0;
  //
  // if(facultyTree -> isEmpty()){
  //   cout << "No faculty records..." << endl;
  // }
  // else{
  //   cout << "Please Provide a Faculty ID: ";
  //   cin >> facID;
  //
  //   Faculty value = facultyTree.search(facID);
  //
  //   if(value.id >= 0){
  //     //initialize to beginning of list
  //     ListNode<int> * node = value.adviseeID -> front;
  //
  //     if(node == NULL){
  //       cout << "No advisees found..." << endl;
  //     }
  //     else{
  //       while(true){
  //         Student studID;
  //         studID.id = node -> data;
  //
  //         Student s = studentTree.search(studID);
  //
  //         cout << s.id << " | " << s.name << " | " << s.level << " | " << s.major << " | " << s.gpa << endl;
  //
  //         if(node -> next != NULL){
  //           node = node -> next;
  //         }
  //         else{
  //           break;
  //         }
  //       }
  //     }
  //   }
  //   else{
  //     cout << "Faculty not found..." << endl;
  //   }
  // }
// }
//
// void Menu::addStudent(){
//Student* s = new Student();
  //
  // cout << "Please enter the student's information below:" << endl;
  //
  // int id;
  // cout << "Student ID: ";
  // cin >> id;
  // s -> ID = id;
  //
  // string name;
  // cout << "Student Name: ";
  // cin >> name;
  // s -> name = name;
  //
  // string grade;
  // cout << "Grade Level: ";
  // cin >> grade;
  // s -> level = grade;
  //
  // string major;
  // cout << "Major: ";
  // cin >> major;
  // s -> major = major;
  //
  // double gpa;
  // cout << "GPA: ";
  // cin >> gpa;
  // s -> gpa = gpa;
  //
  // int advisorID;
  // cout << "Advisor's ID: ";
  // cin >> advisorID;
  // s -> advisor = advisorID;
// }
//
// void Menu::deleteStudent(){
  // int studID = 0;
  // foundStudent = false;
  //
  // while(foundStudent == false){
  //   if(studentTree -> isEmpty()){
  //     cout << "No student records found..." << endl;
  //     return;
  //   }
  //   else{
  //     cout << "Please enter the ID of the student you would like to delete: ";
  //     cin >> studID;
  //   }
  //   studentTree.delete(studID);
  // }
// }
//
// void Menu::addFaculty(){
//Faculty* f = new Faculty();
  //
  // cout << "Please enter the faculty's information below:" << endl;
  //
  // int id;
  // cout << "Faculty ID: ";
  // cin >> id;
  // f -> ID = id;
  //
  // string name;
  // cout << "Faculty Name: ";
  // cin >> name;
  // f -> name = name;
  //
  // string level;
  // cout << "Seniority: ";
  // cin >> level;
  // f -> level = level;
  //
  // string dept;
  // cout << "Department: ";
  // cin >> dept;
  // f -> dept = dept;
  //
  // int adviseeID;
  // cout << "Advisee's ID: ";
  // cin >> adviseeID;
  // f -> advisees = adviseeID;
// }
//
// void Menu::deleteFaculty(){
// int facID = 0;
// foundFaculty = false;
//
// while(foundFaculty == false){
//   if(facultyTree -> isEmpty()){
//     cout << "No faculty records found..." << endl;
//     return;
//   }
//   else{
//     cout << "Please enter the ID of the faculty you would like to delete: ";
//     cin >> facID;
//   }
//   facultyTree.delete(facID);
// }
// }
//
// void Menu::changeAdvisor(){
//   int studID = 0;
//   int facID = 0;
//
//   if(studentBST -> isEmpty()){
//     cout << "No student records found..." << endl;
//     return;
//   }
//   else{
//     cout << "Student ID: ";
//     cin >> studID;
//
//     cout << "Please choose a faculty member from below: " << endl;
//     printAllFaculty();
//
//     cout << "Faculty ID: ";
//     cin >> facID;
//
//     studentTree -> setAdvisor(studID);
//   }
// }
