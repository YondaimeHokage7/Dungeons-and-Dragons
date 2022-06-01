#pragma once
#include <iostream>

class CellIndex
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
};

std::ostream& operator<<(std::ostream& os, const CellIndex& cindex);

