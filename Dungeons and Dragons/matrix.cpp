#include "matrix.hpp"


Matrix::Matrix(int _columns, int _rows) : columns(_columns), rows(_rows), matrix(nullptr)
{
    setMatrix(_columns + 2, _rows + 2); // + 2 for walls on each side
    addDots();
    addWalls();
}

Matrix::Matrix(const Matrix& other): columns(other.columns), rows(other.rows), matrix(nullptr)
{
    setMatrix(other.columns, other.rows);
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other)
    {
        columns = other.columns;
        rows = other.rows;
        setMatrix(other.columns, other.rows);
    }
    return *this;
}

Matrix::~Matrix()
{
    for (int i{0}; i < columns; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::setMatrix(int _columns, int _rows)
{
    delete[] matrix;
    matrix = new char* [_columns];
    for (int i{0}; i < _columns; i++)
    {
        matrix[i] = new char[rows];
    }
}

void Matrix::addDots()
{
    for (int i{1}; i < columns - 1; i++)
    {
        for (int j{1}; j < rows - 1; j++)
        {
            matrix[i][j] = '.';
        }
    }
}

void Matrix::addWalls()
{
    for (int i{0}; i < rows; i++)
    {
        matrix[0][i] = '#';
        matrix[columns - 1][i] = '#';
    }
    for (int i{1}; i < columns - 1; i++)
    {
        matrix[i][0] = '#';
        matrix[i][rows - 1] = '#';
    }
}