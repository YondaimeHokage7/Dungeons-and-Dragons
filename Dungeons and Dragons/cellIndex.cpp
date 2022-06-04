#include "cellIndex.hpp"

CellIndex::CellIndex(int _row, int _column) : row(_row), column(_column)
{}

std::ostream& operator<<(std::ostream& os, const CellIndex& cindex)
{
    return os << '(' << cindex.getRow() << ',' << cindex.getColumn() << ')' << '\n';
}

bool operator!=(const CellIndex& index1, const CellIndex& index2)
{
    { return index1.getRow() != index2.getRow() || index1.getColumn() != index2.getColumn(); }
}

bool operator==(CellIndex& index1, CellIndex& index2)
{
    return index1.getRow() == index2.getRow() && index1.getColumn() == index2.getColumn();
}