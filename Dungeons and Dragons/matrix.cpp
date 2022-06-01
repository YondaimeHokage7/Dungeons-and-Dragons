#include "matrix.hpp"
#include "stack.hpp"
#include "functions.hpp"
#include <iostream>

Matrix::Matrix(int _rows, int _columns) : rows(_rows), columns(_columns), matrix(nullptr)
{
    allocate(_rows, _columns);
    addZeroes();
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), columns(other.columns)
{
    deallocate();
    allocate(rows, columns);
    copy(other);
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other)
    {
        deallocate();
        rows = other.rows;
        columns = other.columns;
        allocate(rows, columns);
        copy(other);
    }
    return *this;
}

Matrix::~Matrix()
{
    for (int i{0}; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::copy(const Matrix& other)
{
    for (int i{0}; i < rows; i++)
    {
        for (int j{0}; j < columns; j++)
        {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

void Matrix::deallocate()
{
    for (int i{0}; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void Matrix::allocate(int _rows, int _columns)
{
    matrix = new char* [_rows];
    for (int i{0}; i < _rows; i++)
    {
        matrix[i] = new char[_columns];
    }
}

void Matrix::addZeroes()
{
    for (int i{0}; i < rows; i++)
    {
        for (int j{0}; j < columns; j++)
        {
            matrix[i][j] = '0';
        }
    }
}

void Matrix::print()
{
    for (int i{0}; i < rows; i++)
    {
        for (int j{0}; j < columns; j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << '\n';
    }
}

Stack* Matrix::generatePaths() const
{
    Stack stack(columns * rows);
    Stack eligible(4);
    Stack* paths = new Stack(columns * rows);
    stack.push(CellIndex(0, 0));
    paths->push(CellIndex(0, 0));
    int numberOfVisited{1};
    matrix[0][0] = '.';
    while (numberOfVisited < columns * rows)
    {
        int numOfEligible{0};
        //Up
        if (stack.peek().getRow() > 0 && matrix[stack.peek().getRow() - 1][stack.peek().getColumn()] == '0')
        {
            eligible.push(CellIndex(stack.peek().getRow() - 1, stack.peek().getColumn()));
            numOfEligible++;
        }
        //Down
        if (stack.peek().getRow() < getRows() - 1 && matrix[stack.peek().getRow() + 1][stack.peek().getColumn()] == '0')
        {
            eligible.push(CellIndex(stack.peek().getRow() + 1, stack.peek().getColumn()));
            numOfEligible++;
        }
        //Left
        if (stack.peek().getColumn() > 0 && matrix[stack.peek().getRow()][stack.peek().getColumn() - 1] == '0')
        {
            eligible.push(CellIndex(stack.peek().getRow(), stack.peek().getColumn() - 1));
            numOfEligible++;
        }
        //Right
        if (stack.peek().getColumn() < getColumns() - 1 && matrix[stack.peek().getRow()][stack.peek().getColumn() + 1] == '0')
        {
            eligible.push(CellIndex(stack.peek().getRow(), stack.peek().getColumn() + 1));
            numOfEligible++;
        }
        //No eligible cells
        if (eligible.getTop() == -1)
        {
            paths->push(stack.peek());
            stack.pop();
        }
        //At least one eligible cell
        else
        {
            CellIndex random = CellIndex(eligible.chooseRandom());
            paths->push(stack.peek());
            stack.push(random);
            matrix[random.getRow()][random.getColumn()] = '.';
            for (int i{0}; i < numOfEligible; i++)
            {
                eligible.pop();
            }
            numberOfVisited++;
        }
    }
    paths->push(stack.peek());
    return paths;
}