// File name: NumberSolver.h
// Author: Vincent Gilliam
// userid: gilliava
// Email: vincent.a.gilliam@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 10
// Honor Statement:I pledge on my honor that I have neither given
// nor received unauthorized aid on this project.
// Description:  h file for NumberSolver
// Last Changed:  12/9/21

#ifndef PROJECT10_NUMBERSOLVER_H
#include "Stack_t.h"

//size of array
const int gridSize = 5;

class NumberSolver{

private:
    int grid[gridSize][gridSize];
    //keep track of the first number of a stack during recursion
    int lowestNum;
    //lowest starting number, but longest list
    int finalLowestNum;
    //stack that is changed to the
    Stack<int> numberSave;
    //stack that is saved
    Stack<int> finalRun;

public:
    //Constructor
    //Pre: initialized grid with a size of 5 * 5
    //Post: User asked for filename, runs loadFromFile()
    NumberSolver();

    //Pre:
    //Post:
    void loadFromFile (const std::string& filename);
    //Pre: receives an x and y coordinate, and an integer
    //Post: inserts the integer into specified place in the array
    void insert(int value, size_t x, size_t y);

    //Pre: receive an x and y coordinate
    //Post: finds the number at the given x and y position, updates lostNum if it's the first
    //      number in the stack, pushes the number into the stack, and checks the eight positions
    //      surrounding the current position. If a potential next position is in the grid and its number is
    //      greater than the current number, it runs the solve function recursively for that position.
    //      If a position cannot move on, it needs to backtrack. It saves the stack into the final run, if it is longer
    //      or the same size and starts with a smaller number. Pops the current number out of the stack
    void solve(size_t x, size_t y);

    //Pre:  receives the number at the current position
    //      and  number at an adjacent position
    //Post: return true is the number at the next position is greater
    //      than the current one
    bool isGreater(int prev, int next);

    //Pre: receives and x and y coordinate
    //Post:returns true is both x and y are greater than or equal to 0
    //     and less than the grid's size (5); checks if it's in the grid
    bool inGrid(size_t x, size_t y);

    //Pre: the longest list has been found
    //Post: Prints out the result
    void print();

};
#define PROJECT10_NUMBERSOLVER_H

#endif