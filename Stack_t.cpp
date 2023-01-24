// File name: Stack_t.cpp
// Author: Vincent Gilliam
// userid: gilliava
// Email: vincent.a.gilliam@vanderbilt.edu
// Class: CS 2201
// Assignment Number: 10
// Honor Statement:I pledge on my honor that I have neither given
// nor received unauthorized aid on this project.
// Description:  cpp file for Stack, has Big 3, push/top/top functions, has been templatized
// Last Changed:  12/9/21


//constructor
//pre: none
//post: stack is created with size and myHead initialized
template <typename ItemType>
Stack<ItemType>::Stack(): mySize(0), myHead(nullptr)
{
}

// Copy Constructor
// pre: parameter object, rhs, exists
// post: stack is created to be a copy of the parameter stack
template <typename ItemType>
Stack<ItemType>::Stack(const Stack<ItemType>& rhs) : mySize(rhs.mySize), myHead(nullptr){
    if(rhs.myHead != nullptr){
        //first node
        myHead = new Node;
        myHead->val = rhs.myHead->val;
        myHead->next = nullptr;
        //the rest
        StackNodePtr newPtr = myHead;
        StackNodePtr origPtr = rhs.myHead;
        while(origPtr->next != nullptr){
            origPtr = origPtr->next;
            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->val = origPtr->val;
            newPtr->next = nullptr;
        }
    }
}


// Class Deconstructor
// pre: the stack exists
// post: the stack is destroyed and any dynamic memory is returned to the system
template <typename ItemType>
Stack<ItemType>::~Stack(){
    while(!isEmpty()){
        pop();
    }
}

// Assignment operator
// Assigns a stack to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
template <typename ItemType>
const Stack<ItemType> & Stack<ItemType>::operator= (const Stack<ItemType>& rhs){
    if(this != &rhs){
        Stack temp = rhs;
        std::swap(myHead, temp.myHead);
        std::swap(mySize, temp.mySize);
    }
    return *this;
}

// isEmpty
// Checks if the stack is empty
// pre:  A stack exists.
// post: Returns true if it IS empty, false if NOT empty.
template <typename ItemType>
bool Stack<ItemType>::isEmpty() const{
    return mySize == 0;
}

// push
// Pushes an item on top of the stack.
// pre:  Stack exists and item is passed.
// post: the item is placed on top of the stack, and size is incremented.
template <typename ItemType>
void Stack<ItemType>::push(const ItemType& item){
        StackNodePtr temp = new Node;
        temp->val = item;
        StackNodePtr save = myHead;
        myHead = temp;
        temp->next = save;
        mySize++;
}

// pop
// Pops the top item off the stack.
// pre:  Stack exists.
// post: Removes item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
template <typename ItemType>
void Stack<ItemType>::pop(){
    if(!isEmpty()){
            StackNodePtr skipped = myHead;
            myHead = myHead->next;
            delete skipped;
            mySize--;
    }
    else{
        throw std::underflow_error("The stack is empty");
    }

}

// top
// Returns the top item of the stack without popping it.
// pre:  Stack exists.
// post: Returns item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
template <typename ItemType>
ItemType Stack<ItemType>::top() const{
    if(isEmpty()){
        throw std::underflow_error("The stack is empty");
    }
    return myHead->val;
}


// size
// Returns the number of items on the stack.
// post: Returns size from the private section of class.
template <typename ItemType>
size_t Stack<ItemType>::size() const{
    return mySize;
}