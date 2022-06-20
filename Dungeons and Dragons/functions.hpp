#pragma once
#include "cellIndex.hpp"

/// A function generating a random integer in a given range
int randomBetween(int num1, int num2);
/// Returns the length of a string
int myStrlen(const char* string);
/// Compares two strings
bool myStrcmp(const char* string1, const char* string2);
/// Checks whether or not two cells are connected 
bool areConnected(CellIndex cell1, CellIndex cell2, CellIndex* connections, int size);
/// Ensures the validity of the entered point
void ensureValidity(int answer, int points);