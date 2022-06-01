#pragma once
#include <iostream>

struct CellIndex
{
    int row, column;

    CellIndex(int _row = 0, int _column = 0) : row(_row), column(_column)
    {}

    int getRow() const{ return row; }

    int getColumn() const { return column; }

    void addI() { ++row; }

    void addJ() { ++column; }

    bool operator==(CellIndex& other)
    {
        return row == other.row && column == other.column;
    }

    friend std::ostream& operator<<(std::ostream& os, const CellIndex& cindex)
    {
        return os << '(' << cindex.row << ',' << cindex.column << ')' << '\n';
    }
};



