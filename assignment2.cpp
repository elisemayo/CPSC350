/*  Elise May
    Student ID: 2271041
    Email: may137@mail.chapman.edu
    CPSC 350-02
    Assignment 2 - Game of Life
*/

#include "assignment2.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <math.h>
#include <time.h>
#include <unistd.h>

using namespace std;

assignment2(){
  int genCount = 0;
  int length = 0;
  int width = 0;
  double popDensity = 0.0;
  bool valid = true;
  int cell = 0;
  int randLength = 0;
  int randWidth = 0;
  int numCells = 0;
  bool stable = true;
  bool enter = true;
  string outputType = "";

  ofstream genFile;
}

~assignment2(){}

void assignment2::settings(){
	string setting = "";
	bool correct = false;
	bool incorrect = true;
  string outputType = "";
  string outFileName = "";

	while(incorrect == true){
		cout << "How would you like the grid printed?" << endl;
    cout << "Type 'pause' if you would like to pause between generations." << endl;
    cout << "Type 'enter' if you would like to press enter to move between generations." << endl;
    cout << "Type 'file' if you would like to print the generations to a file." << endl;
		cin >> outputType;

		if((outputType == "pause")||(outputType == "Pause")){
			incorrect = false;

		}else if((outputType == "enter")||(outputType == "Enter")){
			incorrect = false;

		}else if((outputType == "file")||(outputType == "File")){
			cout << "Please type the file name you would like to print to (include '.txt'): " << endl;
			cin >> outFileName;
			incorrect = false;

		}else{
			cout << "Not quite right... Try again, idiot." << endl;
			incorrect = true;
		}
	}

	while(correct == false){
		string outFileName = "";
		cout << "Would you like us to generate a random grid or would you like to submit your own? (type 'random' or 'file')" << endl;
		cin >> setting;

		if((setting == "random") || (setting == "Random")) {
			int length = 0;
			int width = 0;

			randGrid(length, width);

			correct = true;

		}else if((setting == "file")||(setting == "File")){
			string fileName;

			cout << "Please enter the file name (include .txt): " << endl;
			cin >> fileName;
			userGrid(fileName);

			correct = true;
		}else{
			cout << "Nope and nope. Try again, sis." << endl;

			correct = false;
		}
	}
}

assignment2::randGrid(){
  bool valid = false;
  double popDensity = 0.0;
  int numCells = 0;
  int randLength = 0;
  int randWidth = 0;

  //taking in specs from user input
  cout << "Enter grid length: " << endl;
  cin >> length;

  cout << "Enter grid width: " << endl;
  cin >> width;

  while (valid == false){
  	cout << "Choose a number between 0 and 1 to represent the population density: " << endl;
  	cin >> popDensity;

  	if((popDensity >= 0.0) && (popDensity <= 1.0)){
  			valid = true;
  		}else{
  			valid = false;
  		}
  	}

    //generating temporary grid
  	char** tempGrid = new char*[length];

      for (int i = 0; i < length; ++i) {
        	tempGrid[i] = new char[length];
      }

  	numCells = round((length * width) * popDensity);

  	for (int i = 0; i < length; i++){
      //generating empty grid
  		for (int j = 0; j < width; j++){
  			tempGrid[i][j] = '-';
  		}
  	}
    //generating random values
  	srand(time(NULL));

  	for (int k = 0; k < numCells; ++k){
  		randLength = rand() % (length);
  		randWidth = rand() % (width);

  		bool loop = true;

      //populate the grid randomly
  		while(loop = true){
  			if(tempGrid[randLength][randWidth] == '-'){
  			 	 tempGrid[randLength][randWidth] = 'X';
  				 loop = false;

  			}else{
  				randLength = rand() % (length);
  				randWidth = rand() % (width);
  			}
  		}
  	}
    //continue to select mode for game
  	selectMode(length, width, transGrid);
}

assignment2::userGrid(string inputFile){
  ifstream inputStream;
 	inputStream.open(inputfile.c_str());

  string line = "";
  int read = 0;
 	int length = 0;
 	int width = 0;
  int row = 0;

 	while(!inputStream.eof()){
    //reading in file
 		getline(inputStream, line);
    //converting input strings to ints
 		if (read == 0){
 			length = atoi(line.c_str());

 		} else if (read == 1){
 			width = atoi(line.c_str());

 		} else {
 			break;
 		}
 		read++;
 	}
 	read = 0;

  //generating temporary grid
 	char** tempGrid = new char*[length];

  for (int i = 0; i < length; ++i) {
       	tempGrid[i] = new char[length];
  }

  //generating empty grid
  for (int i = 0; i < length; i++){
 		for (int j = 0; j < width; j++){
 			tempGrid[i][j] = '-';
 		}
 	}
  //seeks arbitrary position in file and positions at beginning
 	inputStream.seekg(0, inputStream.beg);

  //populate grid from values in file
 	while(!inputStream.eof()){
 		getline(inputStream, line);

 		if (read == 0){
      continue;
 		} else if (read == 1){
      continue;
 		} else {
 			for(int i = 0; i < width; i++){
 				char e = line[i];
 				tempGrid[row][i] = e;
 			}
 			row++;
 		}
 		read++;
  }
  inputStream.close();
  //continue to select mode for game
  selectMode(length, width, tempGrid);
}

assignment2::selectMode(int& length, int& width, char**& tempGrid){
  string mode = "";
	bool next = true;

	while(continue == true){
		cout << "Pick your poison o.O" << endl;
    cout << "Select mode: Classic, Doughnut, or Mirror" << endl;
		cin >> mode;

		if((mode == "Classic") || (mode == "classic")) {
			classic(length, width, tempGrid);
			next = false;

    }else if((mode == "Doughnut") || (mode == "doughnut")){
      doughnut(length, width, tempGrid);
      next = false;

		}else if((mode == "Mirror") || (mode == "mirror")){
			mirror(length, width, tempGrid);
			next = false;

		}else{
			next = true;
		}
	}
}

assignment2::checkStable(char ** tempGrid, char ** nextGrid, int length, int width){
  bool stable = true;

  for(int i = 1; i < length-1; ++i){
    for (int j = 0; j < width-1; ++j){
      if (tempGrid[i][j] != nextGrid[i][j]){ //change to proper grids
        stable = false;
      }
    }
  }
  return stable;
}

assignment2::classic(int length&, int width&, char**& tempGrid){
  int count = 0;
	int genCount = 1;
	bool stable = false;

    //creating grid for next generation
    char** nextGrid = new char*[length];

    for (int i = 0; i < length; ++i){
    	nextGrid[i] = new char[width];
    }

    while(stable == false){
	    for (int i = 0; i < length; ++i){
    	    for (int j = 0; j < wWidth; ++j){
              //re-initialize to start again
        	    count = 0;
            	if (i == 0 && j == 0){
               		if (tempGrid[i+1][j] == 'X') count++;
	                if (tempGrid[i][j+1] == 'X') count++;
    	            if (tempGrid[i+1][j+1] == 'X') count++;
        	    }

              else if (i == (length - 1) && j == 0){
        	        if (tempGrid[i-1][j] == 'X') count++;
            	    if (tempGrid[i][j+1] == 'X') count++;
                	if (tempGrid[i-1][j+1] == 'X') count++;
	            }

            	else if (i == 0 && j == (width - 1)){
                	if (tempGrid[i+1][j] == 'X') count++;
            	    if (tempGrid[i][j-1] == 'X') count++;
                	if (tempGrid[i+1][j-1] == 'X') count++;
	            }

    	        else if (i == (length - 1) && j == (width - 1)){
        	        if (tempGrid[i-1][j] == 'X') count++;
            	    if (tempGrid[i][j-1] == 'X') count++;
                	if (tempGrid[i-1][j-1] == 'X') count++;
	            }

    	        //checking edges of grid
        	    else if (i == 0){
            	    if (tempGrid[i+1][j] == 'X') count++;
	                if (tempGrid[i][j+1] == 'X') count++;
    	            if (tempGrid[i+1][j+1] == 'X') count++;
        	        if (tempGrid[i][j-1] == 'X') count++;
	                if (tempGrid[i+1][j-1] == 'X') count++;
    	        }

        	    else if (j == 0){
            	    if (tempGrid[i-1][j] == 'X') count++;
                	if (tempGrid[i+1][j] == 'X') count++;
	                if (tempGrid[i][j+1] == 'X') count++;
    	            if (tempGrid[i+1][j+1] == 'X') count++;
        	        if (tempGrid[i-1][j+1] == 'X') count++;
            	}

              else if (j == (width - 1)){
                	if (tempGrid[i-1][j] == 'X') count++;
	                if (tempGrid[i+1][j] == 'X') count++;
    	            if (tempGrid[i][j-1] == 'X') count++;
        	        if (tempGrid[i+1][j-1] == 'X') count++;
            	    if (tempGrid[i-1][j-1] == 'X') count++;
	            }

	            else if (i == (length - 1)){
    	            if (tempGrid[i-1][j] == 'X') count++;
        	        if (tempGrid[i][j+1] == 'X') count++;
            	    if (tempGrid[i-1][j+1] == 'X') count++;
	                if (tempGrid[i][j-1] == 'X') count++;
    	            if (tempGrid[i-1][j-1] == 'X') count++;
        	    }

    	        else{
        					if(tempGrid[i+1][j] == 'X') count++;
        					if(tempGrid[i][j+1] == 'X') count++;
        					if(tempGrid[i+1][j+1] == 'X') count++;
        					if(tempGrid[i][j-1] =='X') count++;
        					if(tempGrid[i-1][j] == 'X') count++;
        					if(tempGrid[i-1][j-1] == 'X') count++;
        					if(tempGrid[i+1][j-1] =='X') count++;
        					if(tempGrid[i-1][j+1] == 'X') count++;
				          }

            //neighbor rules:
            //one or fewer neighbors = death
        		if (count < 2){
	           		nextGrid[i][j] = '-';
    	    	}

            //exactly two neighbors = stabilized
        		else if (count == 2){
            		nextGrid[i][j] = tempGrid[i][j];
	        	}

            //three neighbors = birth
    	    	else if (count == 3){
            		nextGrid[i][j] = 'X';
        		}

            //four or more neighbors = death
        		else if (count > 3){
            		nextGrid[i][j] = '-';
        		}
        	}
        }
      }

      //checking to see if game is stable
      checkStable(char ** tempGrid, char ** nextGrid, int length, int width);


    	if (stable = true){
    		cout << "The population is stable." << endl;
        continue;

    	}else if(stable == false){
        continue;
			}
      printGrid(string outputType, int genCount, char**& tempGrid, int& length, int& width);

      //onto next generation
    	genCount++;
    return 0;
  }

assignment2::doughnut(int length, int width, char** tempGrid){
  int count = 0;
  int genCount = 1;
  bool stable = false;

  //creating grid for next generation
  char** nextGrid = new char*[length];

      for (int i = 0; i < length; ++i) {
          	nextGrid[i] = new char[width];
      }

      while(stable == false){
     		for(int i = 0; i < length; ++i){
  			for(int j = 0; j < width; ++j){
          //re-initialize to start again
  				count = 0;

  				if (i == 0 && j == 0){
  					if(tempGrid[i+1][j] == 'X') count++;
  					if(tempGrid[i][j+1] == 'X') count++;
  					if(tempGrid[i+1][j+1] == 'X') count++;
  					if(tempGrid[length-1][j] == 'X') count++;
  					if(tempGrid[length-1][j+1] == 'X') count++;
            if(tempGrid[i][width-1] == 'X') count++;
            if(tempGrid[i+1][width-1] == 'X') count++;
  					if(tempGrid[length-1][width-1] == 'X') count++;
  				}

          else if (i == (length - 1) && j == (width - 1)){
  					if(tempGrid[i-1][j] == 'X') count++;
  					if(tempGrid[i][j-1] == 'X') count++;
  					if(tempGrid[i-1][j-1] == 'X') count++;
  					if(tempGrid[0][j-1] == 'X') count++;
  					if(tempGrid[i-1][0] == 'X') count++;
            if(tempGrid[0][j] == 'X') count++;
            if(tempGrid[0][0] == 'X') count++;
            if(tempGrid[i][0] == 'X') count++;
  				}

  				else if (i == 0 && j == (width - 1)){
  					if(tempGrid[i+1][j] == 'X') count++;
  					if(tempGrid[i][j-1] == 'X') count++;
  					if(tempGrid[i+1][j-1] == 'X') count++;
            if(tempGrid[i][0] == 'X') count++;
            if(tempGrid[i+1][0] == 'X') count++;
  					if(tempGrid[length-1][j] == 'X') count++;
  					if(tempGrid[length-1][j-1] == 'X') count++;
  					if(tempGrid[length-1][0] == 'X') count++;
  				}

  				else if (i == (length - 1) && j == 0){
  					if(tempGrid[i-1][j] == 'X') count++;
  					if(tempGrid[i][j+1] == 'X') count++;
  					if(tempGrid[0][j] == 'X') count++;
  					if(tempGrid[0][j+1] == 'X') count++;
            if(tempGrid[i-1][j+1] == 'X') count++;
  					if(tempGrid[0][width-1] == 'X') count++;
  					if(tempGrid[i-1][width-1] == 'X') count++;
  					if(tempGrid[i][width-1] == 'X') count++;
  				}

  				else if (j == 0){
  					if(tempGrid[i-1][j] == 'X') count++;
  					if(tempGrid[i+1][j] == 'X') count++;
  					if(tempGrid[i][j+1] == 'X') count++;
  					if(tempGrid[i+1][j+1] == 'X') count++;
  					if(tempGrid[i-1][j+1] == 'X') count++;
  					if(tempGrid[i-1][width-1] == 'X') count++;
  					if(tempGrid[i][width-1] == 'X') count++;
  					if(tempGrid[i+1][width-1] == 'X') count++;
  				}

  				else if (i == 0){
  					if(tempGrid[i+1][j] == 'X') count++;
  					if(tempGrid[i][j+1] == 'X') count++;
  					if(tempGrid[i+1][j+1] == 'X') count++;
  					if(tempGrid[i][j-1] =='X') count++;
  					if(tempGrid[i+1][j-1] == 'X') count++;
  					if(tempGrid[length-1][j-1] == 'X') count++;
  					if(tempGrid[length-1][j] == 'X') count++;
  					if(tempGrid[length-1][j+1] == 'X') count++;
          }

          else if (i == (length - 1)){
  					if(tempGrid[i-1][j] == 'X') count++;
  					if(tempGrid[i][j+1] == 'X') count++;
  					if(tempGrid[i-1][j+1] == 'X') count++;
  					if(tempGrid[i][j-1] =='X') count++;
  					if(tempGrid[i-1][j-1] == 'X') count++;
  					if(tempGrid[0][j-1] == 'X') count++;
            if(tempGrid[0][j+1] == 'X') count++;
  					if(tempGrid[0][j] == 'X') count++;
  				}

  				else if (j == (width - 1)){
  					if(tempGrid[i-1][j] == 'X') count++;
  					if(tempGrid[i+1][j] == 'X') count++;
            if(tempGrid[i-1][0] == 'X') count++;
            if(tempGrid[i][0] == 'X') count++;
            if(tempGrid[i+1][0] == 'X') count++;
  					if(tempGrid[i][j-1] == 'X') count++;
  					if(tempGrid[i+1][j-1] == 'X') count++;
  					if(tempGrid[i-1][j-1] == 'X') count++;
  				}

  				else{
  					if(tempGrid[i+1][j] == 'X') count++;
  					if(tempGrid[i][j+1] == 'X') count++;
  					if(tempGrid[i+1][j+1] == 'X') count++;
  					if(tempGrid[i][j-1] =='X') count++;
  					if(tempGrid[i-1][j] == 'X') count++;
  					if(tempGrid[i-1][j-1] == 'X') count++;
  					if(tempGrid[i+1][j-1] =='X') count++;
  					if(tempGrid[i-1][j+1] == 'X') count++;
  				}

          //neighbor rules:
          //one or fewer neighbors = death
          if (count < 2){
              nextGrid[i][j] = '-';
          }

          //exactly two neighbors = stabilized
          else if (count == 2){
              nextGrid[i][j] = tempGrid[i][j];
          }

          //three neighbors = birth
          else if (count == 3){
              nextGrid[i][j] = 'X';
          }

          //four or more neighbors = death
          else if (count > 3){
              nextGrid[i][j] = '-';
          }
        }
    	}
    }
    //checking to see if game is stable
    checkStable(char ** tempGrid, char ** nextGrid, int length, int width);


    if (stable = true){
      cout << "The population is stable." << endl;
      continue;

    }else if(stable == false){
      continue;
    }
    printGrid(string outputType, int genCount, char** tempGrid, int length, int width);

    //onto next generation
    genCount++;
  return 0;
}

assignment2::mirror(int length, int width, char** tempGrid){
  int count = 0;
  int genCount = 1;
  bool stable = false;

  //creating grid for next generation
  char** nextGrid = new char*[length];

      for (int i = 0; i < length; ++i) {
          	nextGrid[i] = new char[width];
      }

      while(stable == false){
     		for(int i = 0; i < length; ++i){
  			for(int j = 0; j < width; ++j){
          //re-initialize to start again
  				count = 0;

          if (i == 0 && j == 0){
            if(tempGrid[i+1][j+1] == 'X') count++;
  					if(tempGrid[i+1][j] == 'X') count+=2;
  					if(tempGrid[i][j+1] == 'X') count+=2;
  					if(tempGrid[i][j] == 'X') count+=3;
  				}

  				else if (i == 0 && j == (width - 1)){
            if(tempGrid[i+1][j-1] == 'X') count++;
  					if(tempGrid[i+1][j] == 'X') count+=2;
  					if(tempGrid[i][j-1] == 'X') count+=2;
  					if(tempGrid[i][j] == 'X') count+=3;
  				}

          else if (i == (length - 1) && j == 0){
            if(tempGrid[i-1][j+1] == 'X') count++;
            if(tempGrid[i-1][j] == 'X') count+=2;
            if(tempGrid[i][j+1] == 'X') count+=2;
            if(tempGrid[i][j] == 'X') count+=3;
          }

          else if (i == 0){
           if(board[i+1][j] == 'X') count++;
           if(board[i+1][j+1] == 'X') count++;
           if(board[i+1][j-1] == 'X') count++;
           if(board[i][j] == 'X') count++;
           if(board[i][j+1] == 'X') count+=2;
           if(board[i][j-1] =='X') count+=2;
          }

          else if (j == 0){
           if(board[i][j+1] == 'X') count++;
           if(board[i+1][j+1] == 'X') count++;
           if(board[i-1][j+1] == 'X') count++;
           if(board[i][j] == 'X') count++;
           if(board[i-1][j] == 'X') count+=2;
           if(board[i+1][j] == 'X') count+=2;
         }

  				else if (i == (length - 1 ) && j == (width - 1)){
            if(tempGrid[i-1][j-1] == 'X') count++;
  					if(tempGrid[i-1][j] == 'X') count+=2;
  					if(tempGrid[i][j-1] == 'X') count+=2;
  					if(tempGrid[i][j] == 'X') count+=3;
  				}

  	      else if (i == (length - 1)){
  					if(tempGrid[i-1][j] == 'X') count++;
  					if(tempGrid[i-1][j+1] == 'X') count++;
  					if(tempGrid[i-1][j-1] == 'X') count++;
  					if(tempGrid[i][j] == 'X') count++;
            if(tempGrid[i][j+1] == 'X') count+=2;
            if(tempGrid[i][j-1] =='X') count+=2;
  				}

  				else if (j == (width - 1)){
  					if(tempGrid[i][j-1] == 'X') count++;
  					if(tempGrid[i+1][j-1] == 'X') count++;
  					if(tempGrid[i-1][j-1] == 'X') count++;
  					if(tempGrid[i][j] == 'X') count++;
            if(tempGrid[i-1][j] == 'X') count+=2;
  					if(tempGrid[i+1][j] == 'X') count+=2;
  				}

  				else{
  					if(tempGrid[i+1][j] == 'X') count++;
  					if(tempGrid[i][j+1] == 'X') count++;
  					if(tempGrid[i+1][j+1] == 'X') count++;
  					if(tempGrid[i][j-1] =='X') count++;
  					if(tempGrid[i-1][j] == 'X') count++;
  					if(tempGrid[i-1][j-1] == 'X') count++;
  					if(tempGrid[i+1][j-1] =='X') count++;
  					if(tempGrid[i-1][j+1] == 'X') count++;
            }

          //neighbor rules:
          //one or fewer neighbors = death
          if (count < 2){
              nextGrid[i][j] = '-';
          }

          //exactly two neighbors = stabilized
          else if (count == 2){
              nextGrid[i][j] = tempGrid[i][j];
          }

          //three neighbors = birth
          else if (count == 3){
              nextGrid[i][j] = 'X';
          }

          //four or more neighbors = death
          else if (count > 3){
              nextGrid[i][j] = '-';
          }
        }
    	}
    }
    //checking to see if game is stable
    checkStable(char ** tempGrid, char ** nextGrid, int length, int width);


    if (stable = true){
      cout << "The population is stable." << endl;
      continue;

    }else if(stable == false){
      continue;
    }
    printGrid(string outputType, int genCount, char** tempGrid, int length, int width);

    //onto next generation
    genCount++;
  return 0;
}

assignment2::printGrid(string outputType, int genCount, char** tempGrid, int length, int width){
  bool enter = false;

  //prints to terminal after pause
  if((outputType == "pause")||(outputType == "Pause")){
    //pauses for 1 second
		sleep(1);

  	cout << "Generation: " << genCount << endl;

  	for(int i = 0; i < length; ++i) {
  			for (int j = 0; j < width; ++j) {
  				cout << tempGrid[i][j];
  			}
  			cout << endl;
  	 }

    //prints when enter key is pressed
  	}else if((outputType == "enter")||(outputType == "Enter")){
  		cout << "Press enter key to continue... " << endl;
  		cin.get();

  		if (cin.get()){
  			enter = true;
  		}

  		if (enter = true){
  			cout << "Generation: " << genCount << endl;

  			for(int i = 0; i < length; ++i) {
  				for (int j = 0; j < width; ++j) {
  					cout << tempGrid[i][j];
  				}
  				cout << endl;
  			}
  		}
    //prints to output file
  	}else if((outputType == "file")||(outputType == "File")){
      cout << "Generation: " << genCount << endl;
      printToFile();
    }
  }

  //prints grid to a file
  assignment2::printToFile(ofstream){
    ofstream genFile ("Generations.txt");
    if(genFile.is_open()){
      for(int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
      genFile << tempGrid[i][j];
        }
      }
      genFile.close();
    }else{
      cout << "Unable to open file." << endl;
    }
    return 0;
  }
