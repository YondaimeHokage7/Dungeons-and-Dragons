#pragma once
#include "functions.hpp"
#include "cellIndex.hpp"

class Stack
{
private:
    int capacity;
    int top;
    CellIndex* elements;
public:

    Stack(int _capacity = 0);

    Stack(const Stack&);

    Stack& operator=(const Stack&);

    ~Stack();

    void push(CellIndex);

    void resize();

    bool full() const;

    bool empty() const;

    int getTop() const { return top; }

    CellIndex chooseRandom() const { return elements[randomBetween(0, top)]; }

    CellIndex& peek() const;

    CellIndex pop();

    CellIndex* getElements() const;
};
