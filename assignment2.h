/*  Elise May
    Student ID: 2271041
    Email: may137@mail.chapman.edu
    CPSC 350-02
    Assignment 2 - Game of Life
*/

#include <iostream>
#include <fstream>

using namespace std;

class assignment2{
    public:
        assignment2();
        ~assignment2();

        int genCount;
        int length;
        int width;
        double popDensity;
        bool valid;
        int cell;
        int randLength;
        int randWidth;
        int numCells;
        bool stable;
        bool enter;
        string outputType;

        ofstream genFile;

        //game settings (pause/enter/file and random/user grid)
        void settings();

        //generate grids:
        //from file
        char** userGrid(string inputFile);
        //from variables
        char** randGrid(int length, int width);

        //checks if population is stable
        bool checkStable(char ** tempGrid, char ** nextGrid, int length, int width);

        //select game mode
        void selectMode(int length, int width, char** tempGrid);

        //game modes
        void classic(int length, int width, char** tempGrid);
        void doughnut(int length, int width, char** tempGrid);
        void mirror(int length, int width, char** tempGrid);

        //print grid
        void printGrid(string outputType, int genCount, char** tempGrid, int length, int width);
        void printToFile(ofstream);
};
