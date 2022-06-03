#include <iostream>
#include <cassert>
#include "stack.hpp"

Stack::Stack(int _capacity) : elements(nullptr), capacity(_capacity), top(-1)
{
    delete[] elements;
    elements = new CellIndex[capacity]{};
}

Stack::Stack(const Stack& other) : elements(nullptr), capacity(other.capacity), top(other.top)
{
    copyElements(other);
}

Stack& Stack::operator=(const Stack& other)
{
    if (this != &other)
    {
        delete[] elements;
        capacity = other.capacity;
        top = other.top;
        copyElements(other);
    }
    return *this;
}

Stack::~Stack()
{
    delete[] elements;
}

void Stack::push(const CellIndex& element)
{
    assert(capacity > 0);
    if (full())
    {
        resize();
    }
    elements[++top] = element;
}

void Stack::resize()
{
    int newCapacity{capacity * 2};
    CellIndex* newElements = new CellIndex[newCapacity];
    for (int i{0}; i <= top; i++)
    {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    capacity = newCapacity;
}

CellIndex Stack::pop()
{
    assert(!empty());
    return elements[top--];
}

CellIndex& Stack::peek() const
{
    assert(!empty());
    return elements[top];
}

bool Stack::full() const
{
    return top == capacity - 1;
}

bool Stack::empty() const
{
    return top == EMPTY_STACK;
}

void Stack::copyElements(const Stack& other)
{
    elements = new CellIndex[capacity];
    for (int i{0}; i <= top; i++)
    {
        elements[i] = other.elements[i];
    }
}