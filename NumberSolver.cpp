// File name: NumberSolver.cpp
// Author: Vincent Gilliam
// userid: gilliava
// Email: vincent.a.gilliam@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 10
// Honor Statement:I pledge on my honor that I have neither given
// nor received unauthorized aid on this project.
// Description:  cpp file for NumberSolver
// Last Changed:  12/9/21

#include <string>
#include <fstream>
#include <iostream>
#include "NumberSolver.h"

//Constructor
//Pre: initialized grid with a size of 5 * 5
//Post: User asked for filename, runs loadFromFile()
NumberSolver::NumberSolver(){
    std::string filename;
    std::cout << "Please enter filename: " << std::endl;
    std::cin >> filename;
    loadFromFile(filename);
}
//Pre: receives a filename
//Post: checks if the file is in the folder, if not alert the user and exits program
//      adds the 25 integers to the grid
void NumberSolver::loadFromFile (const std::string& filename){
    std::ifstream infile;
    infile.open(filename.c_str());
    int val;
    size_t x = 0;
    size_t y = 0;
    if (infile.fail()) {
        std::cout << "Error opening input data file" << std::endl;
        std::cout << "press enter to exit";
        std::cin.get();
        exit(1);
    }
    //add numbers into the grid, cycles through all the positions
    while(infile >> val){
        insert(val,  x, y);
        y++;
        if(y >= 5){
            y = 0;
            x++;
        }
    }
    infile.close();
}
//Pre: receives an x and y coordinate, and an integer
//Post: inserts the integer into specified place in the array
void NumberSolver::insert(int value, size_t x, size_t y) {
    grid[x][y] = value;

}
//Pre: receives and x and y coordinate
//Post:returns true is both x and y are greater than or equal to 0
//     and less than the grid's size (5); checks if it's in the grid
bool NumberSolver::inGrid(size_t x, size_t y){
    return (x >= 0 && x < gridSize) && (y >= 0 && y < gridSize);
}
//Pre:  receives the number at the current position
//      and  number at an adjacent position
//Post: return true is the number at the next position is greater
//      than the current one
bool NumberSolver::isGreater(int prev, int next){
    return prev < next;
}
//Pre: receive an x and y coordinate
//Post: finds the number at the given x and y position, updates lostNum if it's the first
//      number in the stack, pushes the number into the stack, and checks the eight positions
//      surrounding the current position. If a potential next position is in the grid and its number is
//      greater than the current number, it runs the solve function recursively for that position.
//      If a position cannot move on, it needs to backtrack. It saves the stack into the final run, if it is longer
//      or the same size and starts with a smaller number. Pops the current number out of the stack
void NumberSolver::solve(size_t x, size_t y){
    int cur = grid[x][y];
    //keeps track of the first number in the list
    if(numberSave.size() == 0){
        lowestNum = cur;
    }
    //add number to stack
    numberSave.push(cur);
    ////search 8 directions and go into solve again if the
    ////coordinate is in the grid and is greater than the current number
    //north
    if(inGrid(x, y+1) && isGreater(cur, grid[x][y+1])){
        solve(x, y+1);
    }
    //northeast
    if(inGrid(x+1, y+1) && isGreater(cur, grid[x+1][y+1])){
        solve(x+1, y+1);
    }
    //east
    if(inGrid(x+1, y) && isGreater(cur, grid[x+1][y])){
        solve(x+1, y);
    }
    //southeast
    if(inGrid(x+1, y-1) && isGreater(cur, grid[x+1][y-1])){
        solve(x+1, y-1);
    }
    //south
    if(inGrid(x, y-1) && isGreater(cur, grid[x][y-1])){
        solve(x, y-1);
    }
    //southwest
    if(inGrid(x-1, y-1) && isGreater(cur, grid[x-1][y-1])){
        solve(x-1, y-1);
    }
    //west
    if(inGrid(x-1, y) && isGreater(cur, grid[x-1][y])){
        solve(x-1, y);
    }
    //northwest
    if(inGrid(x-1, y+1) && isGreater(cur, grid[x-1][y+1])){
        solve(x-1, y+1);
    }
    //if the current stack is larger than the last one or is the same size but
    //starts with a lower number, copy the stack and lowest number as the
    //final stack
    if((numberSave.size() == finalRun.size() && lowestNum < finalLowestNum)
        || (numberSave.size() > finalRun.size())){
        finalRun = numberSave;
        finalLowestNum = lowestNum;
    }
    //ran out of places to go, back up to last one
    numberSave.pop();

}
//Pre: the longest list has been found
//Post: Prints out the result
void NumberSolver::print(){
    std::cout << "The longest run of increasing integers found was:";
    //copy over stack into a temporary Stack
    //and flip the stack over to print correctly
    Stack<int> temp;
    while(!finalRun.isEmpty()){
        temp.push(finalRun.top());
        finalRun.pop();
    }
    //print out response; run cout until the Stack is empty
    while(!temp.isEmpty()){
        if(temp.size() == 1){
            std::cout << " " << temp.top();
        }else{
            std::cout << " " << temp.top() << "," ;
        }
        temp.pop();
    }
}