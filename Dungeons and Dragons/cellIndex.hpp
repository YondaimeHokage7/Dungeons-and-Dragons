#pragma once
#include <iostream>

/// A class representing a 2D matrix index
class CellIndex
{
private:
    /// Integers representing the index of the current row and column
    int row, column;
public:

    /// Default parameter constructor
    CellIndex(int _row = 0, int _column = 0);

    /// Row selector
    int getRow() const { return row; }

    /// Column selector
    int getColumn() const { return column; }

    /// Mutator that increases the number of rows
    void addI() { ++row; }

    /// Mutator that increases the number of columns
    void addJ() { ++column; }

    /// A function that returns the index of the cell above the current one
    CellIndex up() const { return CellIndex(row - 1, column); }

    /// A function that returns the index of the cell below the current one
    CellIndex down() const { return CellIndex(row + 1, column); }

    /// A function that returns the index of the cell next to the current one (left)
    CellIndex left() const { return CellIndex(row, column - 1); }

    /// A function that returns the index of the cell next to the current one (right)
    CellIndex right() const { return CellIndex(row, column + 1); }

    ///Overloaded >> operator
    friend std::istream& operator>>(std::istream& is, CellIndex& cindex);

};
///Overloaded << operator
std::ostream& operator<<(std::ostream& os, const CellIndex& cindex);

///Overloaded != operator
bool operator!=(const CellIndex& index1, const CellIndex& index2);

///Overloaded == operator
bool operator==(const CellIndex& index1, const CellIndex& index2);

