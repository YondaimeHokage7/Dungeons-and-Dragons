#include "functions.hpp"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

int randomBetween(int num1, int num2)
{
    return std::uniform_int_distribution<>(num1, num2)(gen);
}

int myStrlen(char* string)
{
    int counter{0};
    for (int i{0}; string[i] != '\0'; i++)
    {
        counter++;
    }
    return counter;
}

bool myStrcmp(char* string1, char* string2)
{
    bool result{true};
    if (myStrlen(string1) != myStrlen(string2))
    {
        result = false;
    }
    for (int i{0}; string1[i] != '\0' && string2[i] != '\0' && result; i++)
    {
        if (string1[i] != string2[i])
        {
            result = false;
        }
    }
    return result;
}

bool areConnected(CellIndex cell1, CellIndex cell2, CellIndex* connections, int size)
{
    bool result{false};
    for (int i{0}; i < size && !result; i++)
    {
        if (cell1 == connections[i])
        {
            if (i < size - 1 && i > 0)
            {
                result = connections[i + 1] == cell2 || connections[i - 1] == cell2;
            }
            else if (i < size - 1)
            {
                result = connections[i + 1] == cell2;
            }
            else if (i > 0)
            {
                result = connections[i - 1] == cell2;
            }
        }
    }
    return result;
}
//bool isConnected(Stack* stack, CellIndex start, CellIndex end)