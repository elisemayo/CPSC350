// /*
//  Elise May
//  Student ID: 2271041
//  Email: may137@mail.chapman.edu
//  CPSC 350-02
//  Assignment 5
// */
// #include "Processor.h"
//
// using namespace std;
//
// Processor::Processor(){};
// Processor::~Processor(){};
//
// void Processor::readFile(){
//     ifstream studentFile;
//     ifstream facultyFile;
//
//     //student file
//     int studId = 0;
//     string studName = "";
//     string studLevel = "";
//     double gpa = 0;
//     string major = "";
//     int advisor = -1;
//
//     string line;
//     int numStudents = 0;
//     int lineCount = 1;
//
//     studentFile.open("studentTable.txt");
//
//     if(studentFile.is_open()){
//       try{
//         //total number of students
//        	getline(studentFile, line);
//           if (line != ""){
//             numStudents = stoi(line);
//           }
//       }catch (exception e){
//         cout << "Incorrect file format..." << endl;
//       }
//
//       for(int i = 0; i < (7 * numStudents); ++i){
//         getline(studentFile, line);
//           switch (lineCount){
//             case 1:{
//               if (line != "--"){
//               cout << "Incorrect file format..." << endl;
//               }
//               break;
//             }
//             case 2:{
//               try{
//                 studId = stoi(line);
//               }catch (exception e){
//                 cout << "Incorrect file format..." << endl;
//               }
//               break;
//             }
//             case 3:{
//               studName = line;
//               break;
//             }
//             case 4:{
//               studLevel = line;
//               break;
//             }
//             case 5:{
//               try{
//                 gpa = stod(line);
//               }catch (exception e){
//                 cout << "Incorrect file format..." << endl;
//               }
//               break;
//             }
//             case 6:{
//               major = line;
//               break;
//             }
//             case 7:{
//               try{
//                 advisor = stoi(line);
//                 Student * s = new Student(id, name, level, gpa, major, advisor);
//                 TreeNode<Student> *sNode = new TreeNode<Student>(s, id);
//
//                 studentTree.insert(sNode);
//               }catch (exception e){
//                 cout << "Incorrect file format..." << endl;
//               }
//               break;
//             }
//             default:
//               break;
//           }
//           ++lineCount;
//
//           //reset
//           if(lineCount > 7){
//             lineCount = 1;
//           }
//         }
//       }
//       else{
//         cout << "Student table not found..." << endl;
//       }
//       studentFile.close();
//
//     //faculty file
//     int numFaculty = 0;
//     int facId = 0;
//     string facName = "";
//     string facLevel = "";
//     string dept = "";
//     int advisees = 0;
//
//     lineCount = 1;
//     int facCount = 0;
//     int numAdvisees = 0;
//
//     facultyFile.open("facultyTable.txt");
//
//     if(facultyFile.is_open()){
//       try{
//         getline(facultyFile, line);
//
//         if(line != ""){
//           numFaculty = stoi(line);
//         }
//       }catch(exception e){
//         cout << "Incorrect file format..." << endl;
//         }
//       while(getline(facultyFile, line)){
//         switch(lineCount){
//           case 1:{
//             if (line != "--"){
//               cout << "Incorrect file format..." << endl;
//             }
//             break;
//           }
//           case 2:{
//             try{
//               facId = stoi(line);
//             }catch(exception e){
//               cout << "Incorrect file format..." << endl;
//             }
//             break;
//           }
//           case 3:{
//             facName = line;
//             break;
//           }
//           case 4:{
//             facLevel = line;
//             break;
//           }
//           case 5:{
//             dept = line;
//             break;
//           }
//           case 6:{
//             try{
//               numAdvisees = stoi(line);
//             }catch (exception e){
//               cout << "Incorrect file format..." << endl;
//             }
//             Faculty * f = new Faculty(facId, facName, facLevel, dept);
//             facCount++;
//
//             for(int j = 0; j < numAdvisees; ++j){
//               getline(facultyFile, line);
//               try{
//                 adviseeID = stoi(line);
//               }catch(exception e){
//                 cout << "Incorrect file format..." << endl;
//               }
//               f -> addAdvisee(adviseeID);
//             }
//             TreeNode<Faculty> * fNode = new TreeNode<Faculty>(f, facId);
//             facultyTree.insert(fNode);
//             break;
//           }
//           default:
//             break;
//         }
//         ++lineCount;
//
//         if(facCount == numFaculty){
//           break;
//         }
//         //reset
//         if(lineCount > 6){
//           lineCount = 1;
//         }
//       }
//     }
//     else{
//       cout << "Faculty table not found..." << endl;
//     }
//     facultyFile.close();
// }
//
// void Processor::writeFile(){
//   ofstream studentFile;
//   ofstream facultyFile;
//   //student tree
//   studentFile.open("studentTable.txt");
//
//   if(studentFile.is_open()){
//     studentFile << student.getSize() << endl;
//     TreeNode<Student> * node = studentTree * root;
//     outputStudent(node, "studentTable.txt");
//   }
//   studentFile.close();
//
//   //faculty tree
//   facultyFile.open("facultyTable.txt");
//
//   if(facultyFile.is_open()){
//     facultyFile << facultyTree.getSize() << endl;
//     TreeNode<Faculty> * node = facultyTree * root;
//     outputFaculty(node, "facultyTable.txt");
//   }
//   facultyFile.close();
// }
//
// void Processor::outputStudent(TreeNode<Student> * node, string s){
//   ofstream file;
//   file.open(s, true);
//
//   if (node != NULL){
//     file << printStudent() << endl;
//
//     if (node -> left != NULL){
//       outputStudent(node -> left, s);
//     }
//     if (node -> right != NULL){
//       outputStudent(node -> right, s);
//     }
//   }
//   file.close();
// }
//
// void Processor::outputFaculty(TreeNode<Faculty> * node, string s){
//   ofstream file;
//   file.open(s, true);
//
//   if (node != NULL){
//     file << printFaculty() << endl;
//
//     if(node -> left != NULL){
//       outputFaculty(node -> left, s);
//     }
//     if (node -> right != NULL){
//       outputFaculty(node -> right, s);
//     }
//   }
//    else{
//      cout << "Faculty tree is empty..." << endl;
//    }
//    file.close();
// }
//
// string Processor::serialize(){
//   ostringstream output;
//   // if(student){ //how to check for type
//     output << ID << ',' + name + ',' + level + ',' + major + ',' << gpa << ',' << advisorID;
//   }else{
//     output << ID << ',' + name + ',' + level + ',' + dept + ',' << advisees;
//   // }
//   return output.str();
// }
//
// void Processor::deserialize(string serialized){
//   string value;
//   int count = 0;
//
//   stringstream input(serialized);
//
//   while(getline(input, value, ',')){
//     if(count == 0){
//       ID = atoi(value.c_str());
//     }
//     else if(count == 1){
//       name = value;
//     }
//     else if(count == 2){
//       level = value;
//     }
//      // if(student){ //figure out how to check for type
//     else if(count == 3){
//       major = value;
//     }
//     else if(count == 4){
//       gpa = atof(value.c_str());
//     }
//     else if(count == 5){
//       advisorID = atoi(value.c_str());
//     }
//   // }
//   else{
//     else if(count == 3){
//       dept = value;
//     }
//     else if(count == 4){
//       advisees = atoi(value.c_str());
//     }
//   }
//   count++;
//   }
// }
