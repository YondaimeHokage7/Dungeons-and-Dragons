#include "matrix.hpp"
#include "stack.hpp"
#include "functions.hpp"
#include <iostream>

Matrix::Matrix(int _rows, int _columns) : rows(_rows), columns(_columns), matrix(nullptr), connections(nullptr)
{
    allocate(_rows, _columns);
    addZeroes();
    generateMaze();
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), columns(other.columns)
{
    deallocate();
    allocate(rows, columns);
    generateMaze();
    copyElements(other);
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other)
    {
        deallocate();
        rows = other.rows;
        columns = other.columns;
        allocate(rows, columns);
        generateMaze();
        copyElements(other);
    }
    return *this;
}

Matrix::~Matrix()
{
    deallocate();
}

void Matrix::copyElements(const Matrix& other)
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
    delete[] connections;
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

void Matrix::stackToArray(Stack& stack)
{
    connections = new CellIndex[stack.getTop() + 1];
    for (int i{0}; stack.getTop() >= 0; i++)
    {
        connections[i] = stack.pop();
    }
}

void Matrix::generateMaze()
{
    Stack stack(columns * rows);
    Stack eligible(4);
    Stack paths = Stack(columns * rows);
    stack.push(CellIndex(0, 0));
    paths.push(CellIndex(0, 0));
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
        if (eligible.empty())
        {
            paths.push(stack.pop());
            //stack.pop();
        }
        //At least one eligible cell
        else
        {
            CellIndex random = CellIndex(eligible.chooseRandom());
            paths.push(stack.peek());
            stack.push(random);
            matrix[random.getRow()][random.getColumn()] = '.';
            for (int i{0}; i < numOfEligible; i++)
            {
                eligible.pop();
            }
            numberOfVisited++;
        }
    }
    paths.push(stack.peek());
    matrix[0][0] = 'X';
    numberOfConnections = paths.getTop() + 1;
    stackToArray(paths);
}

void Matrix::setElement(CellIndex index, char newValue)
{
    matrix[index.getRow()][index.getColumn()] = newValue;
}