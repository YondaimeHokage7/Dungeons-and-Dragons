#include "stack.hpp"
#include <iostream>

Stack::Stack(int _capacity) : elements(nullptr), capacity(_capacity), top(-1)
{
    delete[] elements;
    elements = new CellIndex[capacity]{};
}

Stack::Stack(const Stack& other) : elements(nullptr), capacity(other.capacity), top(other.top)
{
    delete[] elements;
    elements = new CellIndex[other.capacity]{};
    for (int i{0}; i < capacity; i++)
    {
        elements[i] = other.elements[i];
    }
}

Stack& Stack::operator=(const Stack& other)
{
    if (this != &other)
    {
        delete[] elements;
        elements = new CellIndex[other.capacity]{};
        capacity = other.capacity;
        top = other.top;
        for (int i{0}; i < capacity; i++)
        {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

Stack::~Stack()
{
    delete[] elements;
}

void Stack::push(CellIndex element)
{
    if (!full())
    {
        elements[++top] = element;
    }
    else
    {
        resize();
        elements[++top] = element;
    }
}

void Stack::resize()
{
    int newCapacity{capacity * 2};
    CellIndex* newElements = new CellIndex[newCapacity];
    for (int i{0}; i < newCapacity; i++)
    {
        newElements[i] = elements[i];
    }
    capacity = newCapacity;
    delete[] elements;
    elements = newElements;
}

bool Stack::full() const
{
    return top == capacity - 1;
}

bool Stack::empty() const
{
    return top == -1;
}

CellIndex& Stack::peek() const
{
    return elements[top];
}

CellIndex Stack::pop()
{
    if (!empty())
    {
        return elements[top--];
    }
    else
    {
        std::cerr << "The stack is empty!";
    }
}

CellIndex* Stack::getElements() const
{
    return elements;
}
