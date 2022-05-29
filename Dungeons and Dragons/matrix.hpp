#pragma once
class Matrix
{
private:
    int columns;
    int rows;
    char** matrix;
    void setMatrix(int _columns, int _rows);
    void addDots();
    void addWalls();
public:
    Matrix(int _columns = 0, int _rows = 0);

    Matrix(const Matrix&);

    Matrix& operator=(const Matrix&);

    ~Matrix();

    int getColumns() const { return columns; }

    int getRows() const { return rows; }
};

