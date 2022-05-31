#pragma once
#include "stack.hpp"

class Matrix
{
private:
    int columns;
    int rows;
    char** matrix;
    void setMatrix(int _rows, int _columns);
    void addDots();
    //void addOutsideWalls();
    //void addWalls();
public:
    Matrix(int _rows = 0, int _columns = 0);

    Matrix(const Matrix&);

    Matrix& operator=(const Matrix&);

    ~Matrix();

    Stack* generatePaths();

    int getColumns() const { return columns; }

    int getRows() const { return rows; }

    void print();

    
};
