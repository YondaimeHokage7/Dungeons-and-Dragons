#pragma once
#include "stack.hpp"

/// A matrix class
class Matrix
{
private:
    /// Number of rows
    int rows;

    /// Number of columns
    int columns;

    /// A 2D char array
    char** matrix;

    /// Fills the array with a given character
    void addChar(char character);

    /// Number of moves made by the generateMaze() function
    int numberOfConnections;

    /// A function deallocating the memory of the matrix
    void deallocate();

    /// A function allocating memory to the matrix
    void allocate(int _rows, int _columns);

    /// A function copying the elements of a matrix
    void copyElements(const Matrix&);

    /// A function that copies the elements of the stack used to generate paths to a CellIndex array
    void stackToArray(Stack& stack);

protected:
    /// A CellIndex array keeping track of all possible moves
    CellIndex* connections;
public:
    /// Default parameter constructor
    Matrix(int _rows = 0, int _columns = 0);

    /// Parameter constructor
    Matrix(int _rows, int _columns, int _numberOfConnections, CellIndex* _connections);

    /// Copy constructor
    Matrix(const Matrix&);

    /// Overloaded assignment operator
    Matrix& operator=(const Matrix&);

    /// Destructor
    ~Matrix();

    /// Rows getter
    int getRows() const { return rows; }

    /// Columns getter
    int getColumns() const { return columns; }

    /// A function returning the char at a specified position
    char getElement(CellIndex index) const { return matrix[index.getRow()][index.getColumn()]; }

    /// Connections getter
    CellIndex* getConnections() const { return connections; }

    /// Number of Connections getter
    int getNumberOfConnections() const { return numberOfConnections; }

    /// Element setter
    void setElement(CellIndex index, char newValue);

    /// A function generating the maze
    void generateMaze();
};

