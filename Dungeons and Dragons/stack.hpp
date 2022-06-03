#pragma once
#include "functions.hpp"
#include "cellIndex.hpp"

/// A stack with elements of type CellIndex
class Stack
{
private:
    /// The index of the top element of a stack with no elements
    const int static EMPTY_STACK{-1};
    /// The capacity of the stack
    int capacity;
    /// The index of the current top element
    int top;
    /// An array of the elements in the stack
    CellIndex* elements;
public:
    /// Constructor with default parameters
    Stack(int _capacity = 0);

    /// Copy constructor
    Stack(const Stack&);

    /// Assignment operator
    Stack& operator=(const Stack&);

    /// Destructor
    ~Stack();

    /// Inserts an element at the top of the stack
    void push(const CellIndex& element);

    /// Doubles the capacity of the stack
    void resize();

    /// Removes the element at the top of the stack and returns it
    CellIndex pop();
    
    /// Returns it the element at the top of the stack
    CellIndex& peek() const;
    
    /// Chooses a random element and returns it
    CellIndex& chooseRandom() const { return elements[randomBetween(0, top)]; }

    /// Returns the index of the current top element
    int getTop() const { return top; }

    /// Checks whether the stack is full
    bool full() const;

    /// Checks whether the stack is empty
    bool empty() const;

    /// Copies the elements of other.elements to this->elements to 
    void copyElements(const Stack& other);
};
