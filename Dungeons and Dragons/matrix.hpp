#pragma once
#include "stack.hpp"

class Matrix
{
private:
    int rows;

    int columns;

    char** matrix;

    CellIndex* connections;

    int numberOfConnections;

    void deallocate();

    void allocate(int _rows, int _columns);

    void copyElements(const Matrix&);

    void stackToArray(Stack& stack);
protected:
    void addZeroes();
public:
    Matrix(int _rows = 0, int _columns = 0);

    Matrix(const Matrix&);

    Matrix& operator=(const Matrix&);

    ~Matrix();

    int getRows() const { return rows; }

    int getColumns() const { return columns; }

    char getElement(CellIndex index) const { return matrix[index.getRow()][index.getColumn()]; }

    CellIndex* getConnections() const { return connections; }

    int getNumberOfConnections() const { return numberOfConnections; }

    void setElement(CellIndex index, char newValue);

    void generateMaze();

    //void setMatrix();

};

//char getMatrix(int i, int j) const { return matrix[i][j]; }
//void print();
