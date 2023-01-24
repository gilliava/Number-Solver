// File name: project.cpp
// Author: Vincent Gilliam
// userid: gilliava
// Email: vincent.a.gilliam@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 10
// Honor Statement:I pledge on my honor that I have neither given
// nor received unauthorized aid on this project.
// Description:  cpp file that runs the Number solver program
// Last Changed:  12/9/21

#include "NumberSolver.h"
#include <string>

int main() {
    NumberSolver temp;
    //goes throughout the grid and runs the initial
    //solve() function for each coordinate
    for(size_t i = 0; i < gridSize; i ++){
        for(size_t j = 0; j < gridSize; j++){
            temp.solve(i, j);
        }
    }
    //prints the result
    temp.print();
    return 0;
}
