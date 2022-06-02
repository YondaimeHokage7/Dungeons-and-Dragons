#pragma once
#include "stack.hpp"

class Matrix
{
private:
    int columns;
    int rows;
    char** matrix;
    //void setMatrix(int _rows, int _columns);
    void copy(const Matrix&);
    void deallocate();
    void allocate(int _rows, int _columns);
    void addZeroes();
    //void addOutsideWalls();
    //void addWalls();
public:
    Matrix(int _rows = 0, int _columns = 0);

    Matrix(const Matrix&);

    Matrix& operator=(const Matrix&);

    ~Matrix();

    char getMatrix(int i, int j) const { return matrix[i][j]; }

    Stack* generatePaths() const;

    int getColumns() const { return columns; }

    int getRows() const { return rows; }

    void print();

    void setElement(int i, int j, char newValue);
};