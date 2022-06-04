#pragma once
#include <iostream>

struct CellIndex
{
private:
    int row, column;
public:
    CellIndex(int _row = 0, int _column = 0);

    int getRow() const { return row; }

    int getColumn() const { return column; }

    void addI() { ++row; }

    void addJ() { ++column; }

    CellIndex up() const { return CellIndex(row - 1, column); }

    CellIndex down() const { return CellIndex(row + 1, column); }

    CellIndex left() const { return CellIndex(row, column - 1); }

    CellIndex right() const { return CellIndex(row, column + 1); }
};

std::ostream& operator<<(std::ostream& os, const CellIndex& cindex);
bool operator!=(const CellIndex& index1, const CellIndex& index2);
bool operator==(CellIndex& index1, CellIndex& index2);

