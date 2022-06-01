#pragma once
#include "cellIndex.hpp"

int randomBetween(int num1, int num2);

bool areConnected(CellIndex cell1, CellIndex cell2, CellIndex* connections, int size);