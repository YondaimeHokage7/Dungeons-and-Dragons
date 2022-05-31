#include "matrix.hpp"
#include "stack.hpp"
#include "functions.hpp"
#include <iostream>

Matrix::Matrix(int _rows, int _columns) : rows(_rows), columns(_columns), matrix(nullptr)
{
    setMatrix(_rows, _columns);
    addDots();
    //addOutsideWalls();
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), columns(other.columns), matrix(nullptr)
{
    setMatrix(other.rows, other.columns);
}

Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other)
    {
        rows = other.rows;
        columns = other.columns;
        setMatrix(other.rows, other.columns);
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

void Matrix::setMatrix(int _rows, int _columns)
{
    for (int i{0}; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = new char* [_rows];
    for (int i{0}; i < _rows; i++)
    {
        matrix[i] = new char[_columns];
    }
}

void Matrix::addDots()
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

Stack* Matrix::generatePaths()
{
    Stack stack(columns* rows);
    Stack eligible(4);
    Stack* paths = new Stack(columns * rows);
    //Stack paths(columns * rows);
    stack.push(CellIndex(0, 0));
    //paths->push(CellIndex(0, 0));
    int numberOfVisited{1};
    //CellIndex* connected{new CellIndex[columns * rows]};
    //connected[0] = CellIndex(0, 0);
    matrix[0][0] = '1';
    while (numberOfVisited < columns * rows)
    {
        int numOfEligible{0};
        //Up
        if (stack.peek().row > 0 && matrix[stack.peek().row - 1][stack.peek().column] == '0')
        {
            eligible.push(CellIndex(stack.peek().row - 1, stack.peek().column));
            numOfEligible++;
        }
        //Down
        if (stack.peek().row < getRows() - 1 && matrix[stack.peek().row + 1][stack.peek().column] == '0')
        {
            eligible.push(CellIndex(stack.peek().row + 1, stack.peek().column));
            numOfEligible++;
        }
        //Left
        if (stack.peek().column > 0 && matrix[stack.peek().row][stack.peek().column - 1] == '0')
        {
            eligible.push(CellIndex(stack.peek().row, stack.peek().column - 1));
            numOfEligible++;
        }
        //Right
        if (stack.peek().column < getColumns() - 1 && matrix[stack.peek().row][stack.peek().column + 1] == '0')
        {
            eligible.push(CellIndex(stack.peek().row, stack.peek().column + 1));
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
            matrix[random.row][random.column] = '1';
            //connected[numberOfVisited] = stack.peek();
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
/*
void Matrix::addWalls()
{

}
*/
/*
for (int i{0}; i < columns; i++)
{
    for (int j{0}; j < rows; j++)
    {
        if()
    }
}
*/
/*void Matrix::addOutsideWalls()
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
}*/