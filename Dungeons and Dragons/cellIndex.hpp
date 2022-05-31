#pragma once
#include <iostream>

struct CellIndex
{
    int row, column;

    CellIndex(int _row = 0, int _column = 0) : row(_row), column(_column)
    {}

    void addI() { ++row; }

    void addJ() { ++column; }
    
    friend std::ostream& operator<<(std::ostream& os, const CellIndex& cindex)
    {
        return os << '(' << cindex.row << ',' << cindex.column << ')' << '\n';
    }
};

