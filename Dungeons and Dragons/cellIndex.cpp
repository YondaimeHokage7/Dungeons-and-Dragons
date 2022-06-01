#include "cellIndex.hpp"

CellIndex::CellIndex(int _row, int _column) : row(_row), column(_column)
{}

std::ostream& operator<<(std::ostream& os, const CellIndex& cindex)
{
    return os << '(' << cindex.getRow() << ',' << cindex.getColumn() << ')' << '\n';
}
