#pragma once
#include <iostream>

struct CellIndex
{
    int row, column;

    CellIndex(int _row = 0, int _column = 0) : row(_row), column(_column)
    {}

    /*bool hasBeenVisited(CellIndex* visited, int numberOfVistied)
    {
        bool result{false};
        for (int i{0}; i < numberOfVistied && !result; i++)
        {
            if (this->column == visited[i].column && this->row == visited[i].row)
            {
                result = true;
            }
        }
        return result;
    }*/

    void addI() { ++row; }

    void addJ() { ++column; }
    
    friend std::ostream& operator<<(std::ostream& os, const CellIndex& cindex)
    {
        return os << '(' << cindex.row << ',' << cindex.column << ')' << '\n';
    }
};

