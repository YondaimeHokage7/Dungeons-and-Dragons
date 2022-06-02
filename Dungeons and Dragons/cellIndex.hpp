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

    bool operator==(CellIndex& other) { return row == other.row && column == other.column; }

    CellIndex up() const { return CellIndex(row - 1, column); }

    CellIndex down() const { return CellIndex(row + 1, column); }

    CellIndex left() const { return CellIndex(row, column - 1); }

    CellIndex right() const { return CellIndex(row, column + 1); }
};

std::ostream& operator<<(std::ostream& os, const CellIndex& cindex);

