#include <fstream>
#include <cassert>
#include <iostream>
#include <sstream>
#include "map.hpp"

int Map::remainingMonsters = 0;
int Map::remainingTreasures = 0;

Map::Map(int _level) : level(_level), monsters(getFileStat("Monsters", _level)), treasures(getFileStat("Treasures", _level)), Matrix(getFileStat("Rows", _level), getFileStat("Columns", _level))
{
    addMonsters();
    addTreasures();
    if (level >= 2)
    {
        generateNextFile();
    }
}

Map::Map(int _level, int _monsters, int _treasures, int _rows, int _columns, int _numberOfConnections, CellIndex* _connections, int _remainingMonsters, int _remainingTreasures) : level(_level), monsters(_monsters), treasures(_treasures), Matrix(_rows, _columns, _numberOfConnections, _connections)
{
    remainingMonsters = _remainingMonsters;
    remainingTreasures = _remainingTreasures;
}

int Map::getFileStat(std::string stat, int _level) const
{
    std::stringstream fileNameStream;
    fileNameStream << prefix << _level << suffix;
    std::string filename = fileNameStream.str();
    std::ifstream statFile(filename, std::ios::in);
    assert(statFile.is_open());
    int _rows, _columns, _monsters, _treasures;
    statFile >> _rows >> _columns >> _monsters >> _treasures;
    statFile.close();
    if (stat == "Rows")
        return _rows;
    else if (stat == "Columns")
        return _columns;
    else if (stat == "Monsters")
        return _monsters;
    else if (stat == "Treasures")
        return _treasures;
}

void Map::generateNextFile() const
{
    int current[5]{getLevel(), getRows(), getColumns(), getMonsters(), getTreasures()};
    int previous[5]{getLevel() - 1};
    std::stringstream currentNameStream;
    std::stringstream previousNameStream;
    std::stringstream nextNameStream;
    nextNameStream << prefix << current[0] + 1 << suffix;
    currentNameStream << prefix << current[0] << suffix;
    previousNameStream << prefix << current[0] - 1 << suffix;
    std::string nextName = nextNameStream.str();
    std::string currentName = currentNameStream.str();
    std::string previousName = previousNameStream.str();
    std::ifstream previousLevel(previousName, std::ios::in);
    previousLevel >> previous[1] >> previous[2] >> previous[3] >> previous[4];
    previousLevel.close();
    std::ifstream currentLevel(currentName, std::ios::in);
    currentLevel >> current[1] >> current[2] >> current[3] >> current[4];
    currentLevel.close();
    std::ofstream nextLevel(nextName);
    for (int i{1}; i < 5; i++)
    {
        nextLevel << current[i] + previous[i] << ' ';
    }
}

void Map::printBorder() const
{
    for (int i{0}; i < getColumns() * 3 + (getColumns() - 1) + 2; i++)
    {
        std::cout << '#';
    }
    std::cout << '\n';
}

void Map::print() const
{
    printBorder();
    for (int i{0}; i < getRows() - 1; i++)
    {
        //Prints the left border of the current row
        std::cout << '#';
        //Checks whether two cells are connected and prints the appropriate symbol
        for (int j{0}; j < getColumns() - 1; j++)
        {
            std::cout << ' ' << getElement(CellIndex(i, j)) << ' ';
            if (areConnected(CellIndex(i, j), CellIndex(i, j + 1), getConnections(), getNumberOfConnections()))
            {

                std::cout << ' ';
            }
            else
            {
                std::cout << '#';
            }
        }
        //Prints the last element of the row
        std::cout << ' ' << getElement(CellIndex(i, getColumns() - 1)) << " #\n";
        //prints the left border of the current border row
        std::cout << '#';
        //Prints the current border row
        for (int j{0}; j < getColumns() - 1; j++)
        {
            if (areConnected(CellIndex(i, j), CellIndex(i + 1, j), getConnections(), getNumberOfConnections()))
            {
                //Prints the appropriate sequence of characters depending on the borders between neighbouring cells
                if (!areConnected(CellIndex(i, j), CellIndex(i, j + 1), getConnections(), getNumberOfConnections()) || !areConnected(CellIndex(i, j), CellIndex(i + 1, j + 1), getConnections(), getNumberOfConnections()))
                {
                    std::cout << "   #";
                }
                else
                {
                    std::cout << "    ";
                }
            }
            else
            {
                std::cout << "####";
            }
        }
        //Prints the last row of the map
        if (areConnected(CellIndex(i, getColumns() - 1), CellIndex(i + 1, getColumns() - 1), getConnections(), getNumberOfConnections()))
        {
            std::cout << "   #"; // remove # if not working
        }
        else
        {
            std::cout << "####"; // remove # if not working and restore 154
        }
        //std::cout << '#';
        std::cout << '\n';
    }
    std::cout << '#';
    //Prints the last row
    for (int i{0}; i < getColumns() - 1; i++)
    {
        int currentRow{getRows() - 1};
        std::cout << ' ' << getElement(CellIndex(currentRow, i)) << ' ';
        if (areConnected(CellIndex(currentRow, i), CellIndex(currentRow, i + 1), getConnections(), getNumberOfConnections()))
        {
            std::cout << ' ';
        }
        else
        {
            std::cout << '#';
        }
    }
    //prints the last element
    std::cout << ' ' << getElement(CellIndex(getRows() - 1, getColumns() - 1)) << " #\n";
    printBorder();
}

void Map::addTreasures()
{
    int _treasures{0};
    while (_treasures < treasures)
    {
        CellIndex random(randomBetween(0, getRows() - 1), randomBetween(0, getColumns()));
        if (getElement(random) == '.' && random != CellIndex(0, 0))
        {
            setElement(random, 'T');
            _treasures++;
            remainingTreasures++;
        }
    }
}

void Map::addMonsters()
{
    int _monsters{0};
    while (_monsters < monsters)
    {
        CellIndex random(randomBetween(0, getRows() - 1), randomBetween(0, getColumns()));
        if (getElement(random) == '.' && random != CellIndex(0,0))
        {
            setElement(random, 'M');
            _monsters++;
            remainingMonsters++;
        }
    }
}

void Map::levelUp()
{
    Map newmap(getLevel() + 1);
    *this = newmap;
}

CellIndex* Map::getMonsterPostitions() const
{
    int arrIndex{0};
    CellIndex* positions = new CellIndex[remainingMonsters];
    for (int i{0}; i < getRows(); i++)
    {
        for (int j{0}; j < getColumns(); j++)
        {
            if (getElement(CellIndex(i, j)) == 'M')
            {
                positions[arrIndex] = CellIndex(i, j);
                arrIndex++;
            }
        }
    }
    return positions;
}

CellIndex* Map::getTreasurePostitions() const
{
    int arrIndex{0};
    CellIndex* positions = new CellIndex[remainingTreasures];
    for (int i{0}; i < getRows(); i++)
    {
        for (int j{0}; j < getColumns(); j++)
        {
            if (getElement(CellIndex(i, j)) == 'T')
            {
                positions[arrIndex] = CellIndex(i, j);
                arrIndex++;
            }
        }
    }
    return positions;
}

std::ostream& operator<<(std::ostream& os, const Map& map)
{
    os << map.getLevel() << ' ' << map.getMonsters() << ' ' << map.getTreasures() << ' ' << map.getRows() << ' ' << map.getColumns() << ' ' << map.remainingMonsters << ' ' << map.remainingTreasures << '\n';
    CellIndex* monsterPositions = map.getMonsterPostitions();
    CellIndex* treasurePostitions = map.getTreasurePostitions();
    for (int i{0}; i < map.remainingMonsters; i++)
    {
        os << monsterPositions[i];
    }
    for (int i{0}; i < map.remainingTreasures; i++)
    {
        os << treasurePostitions[i];
    }
    os << map.getNumberOfConnections() << '\n';
    for (int i{0}; i < map.getNumberOfConnections(); i++)
    {
        os << map.getConnections()[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, Map& map)
{
    int level, remainingMonsters, remainingTreasures, dragons, treasures, rows, columns;
    is >> level >> dragons >> treasures >> rows >> columns >> remainingMonsters >> remainingTreasures;
    CellIndex* monsterPositions = new CellIndex[remainingMonsters];
    CellIndex* treasurePostions = new CellIndex[remainingTreasures];
    for (int i{0}; i < remainingMonsters; i++)
    {
        is >> monsterPositions[i];
    }
    for (int i{0}; i < remainingTreasures; i++)
    {
        is >> treasurePostions[i];
    }
    int numberOfConnections;
    is >> numberOfConnections;
    CellIndex* connections = new CellIndex[numberOfConnections];
    for (int i{0}; i < numberOfConnections; i++)
    {
        is >> connections[i];
    }
    Map newMap(level, dragons, treasures, rows, columns, numberOfConnections, connections, remainingMonsters, remainingTreasures);
    map = newMap;
    for (int i{0}; i < map.remainingMonsters; i++)
    {
        map.setElement(monsterPositions[i], 'M');
    }
    for (int i{0}; i < map.remainingTreasures; i++)
    {
        map.setElement(treasurePostions[i], 'T');
    }
    delete[] monsterPositions;
    delete[] treasurePostions;
    return is;
}