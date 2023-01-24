// File name: Stack_t.h
// Author: Vincent Gilliam
// userid: gilliava
// Email: vincent.a.gilliam@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 10
// Honor Statement:I pledge on my honor that I have neither given
// nor received unauthorized aid on this project.
// Description:  h file for Stack, has Big 3, push/top/top functions, has been templatized
// Last Changed:  12/9/21

#ifndef STACK_T_H
#define STACK_T_H
#include <iostream>
template <typename ItemType>
class Stack
{

private:

    //number of nodes in the stack
    size_t mySize;

    //description of node with a double value and a pointer
    struct Node{
        ItemType val;
        Node *next;
    };

    //pointers to the nodes
    typedef Node* StackNodePtr;

    //address that points to first node
    StackNodePtr myHead;


public:
    // Class Constructor
    // post: stack is created & initialized to be empty
    Stack();

    // Copy Constructor
    // pre: parameter object, rhs, exists
    // post: stack is created to be a copy of the parameter stack
    Stack(const Stack& rhs);

    // Class Deconstructor
    // pre: the stack exists
    // post: the stack is destroyed and any dynamic memory is returned to the system
    ~Stack();

    // Assignment operator
    // Assigns a stack to another
    // pre: both class objects exist
    // post: this class object gets assigned a copy of the parameter class object
    const Stack& operator= (const Stack& rhs);

    // isEmpty
    // Checks if the stack is empty
    // pre:  A stack exists.
    // post: Returns true if it IS empty, false if NOT empty.
    bool isEmpty() const;

    // push
    // Pushes an item on top of the stack.
    // pre:  Stack exists and item is passed.
    // post: the item is placed on top of the stack, and size is incremented.
    void push(const ItemType& item);

    // pop
    // Pops the top item off the stack.
    // pre:  Stack exists.
    // post: Removes item on top of stack.  If the stack
    //       was already empty, throws a std::underflow_error exception.
    void pop();

    // top
    // Returns the top item of the stack without popping it.
    // pre:  Stack exists.
    // post: Returns item on top of stack.  If the stack
    //       was already empty, throws a std::underflow_error exception.
    ItemType top() const;

    // size
    // Returns the number of items on the stack.
    // post: Returns size from the private section of class.
    size_t size() const;

};
#include "Stack_t.cpp"
#endif
