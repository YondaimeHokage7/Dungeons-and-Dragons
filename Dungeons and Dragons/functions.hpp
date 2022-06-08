#pragma once
#include "cellIndex.hpp"

int randomBetween(int num1, int num2);

int myStrlen(const char* string);

bool myStrcmp(const char* string1, const char* string2);

bool areConnected(CellIndex cell1, CellIndex cell2, CellIndex* connections, int size);

void ensureValidity(int answer, int points);