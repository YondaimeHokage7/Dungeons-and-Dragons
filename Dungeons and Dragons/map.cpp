#include <fstream>
#include <cassert>
#include <iostream>
#include <sstream>
#include "map.hpp"

Map::Map(int _level) : level(_level), monsters(getFileStat("Monsters", _level)), treasures(getFileStat("Treasures", _level)), Matrix(getFileStat("Rows", _level), getFileStat("Columns", _level))
{
    if (level >= 2)
    {
        generateNextFile();
    }
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
    //Upper border
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
        if (getElement(random) == '.')
        {
            setElement(random, 'T');
            _treasures++;
        }
    }
}

void Map::addMonsters()
{
    int _monsters{0};
    while (_monsters < monsters)
    {
        CellIndex random(randomBetween(0, getRows() - 1), randomBetween(0, getColumns()));
        if (getElement(random) == '.')
        {
            setElement(random, 'M');
            _monsters++;
        }
    }
}

/*void Map::levelUp()
{
    Map newmap(getLevel() + 1);
    level = newmap.getLevel();
    monsters = newmap.getMonsters();
    treasures = newmap.getTreasures();
    map = newmap.getMap();
    //paths = newmap.getMap();

}*/




/*
Map::Map(const Map& other)
{
    level = other.level;
    monsters = other.monsters;
    treasures = other.treasures;
    size = other.size;
    map = other.map;
    paths = other.paths;
    delete[] connections;
    connections = other.connections;
}

Map& Map::operator=(const Map& other)
{
    if (this != &other)
    {
        level = other.level;
        monsters = other.monsters;
        treasures = other.treasures;
        size = other.size;
        map = other.map;
        paths = other.paths;
        delete[] connections;
        connections = other.connections;
    }
    return *this;
}

Map::~Map()
{
    delete[] connections;
}
*/
