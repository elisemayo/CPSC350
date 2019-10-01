Elise May
Student ID: 2271041
Email: may137@mail.chapman.edu
CPSC 350-02
Assignment 2 - Game of Life(Death)

The program simulates the life cycle of bacteria in the form of a game.

Methods:
- settings: user selects output type and grid type
- randGrid: generates random grid
- userGrid: generates grid from user input file
- checkStable: checks to see if the population is stablizing
- selectMode: user selects which mode of game play to use
- classic: play classic game mode
- doughnut: play doughnut game mode
- mirror: play mirror game mode
- printGrid: prints the grid to either the console or a file based on user preference
- printToFile: used within printGrid to print grid to file

Source Files:
- assignment2.h
- assignment2.cpp
- assignment2_main.cpp

References: 
- http://www.cplusplus.com/reference/istream/istream/seekg/ (for using seekg method in userGrid)
- http://www.cplusplus.com/reference/cstdlib/atoi/ (for using atoi method in userGrid)
- http://www.martinbroadhurst.com/sleep-for-milliseconds-in-c.html (for creating pause option)
- http://www.cplusplus.com/reference/istream/istream/get/ (for taking in lines from a file)
- http://www.cplusplus.com/doc/tutorial/files/ (for file reading/writing)

Instructions:
- cd to the directory
- g++ *.* to compile
- ./a.out to run the program