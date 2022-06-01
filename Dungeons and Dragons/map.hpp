#ifndef __MAP_HPP
#define __MAP_HPP

#include <string>
#include "matrix.hpp"

const std::string level1Name = "level1.txt";
const std::string level2Name = "level2.txt";
const std::string prefix = "level";
const std::string suffix = ".txt";

class Map
{
private:
    int level;
    int  monsters, treasures;
    Matrix map;
    void generateNextFile() const;
    void printBorder() const;

public:
    Map(int level = 0);

    int getLevel() const { return level; }

    int getColumns() const { return map.getColumns(); }

    int getRows() const { return map.getRows(); }

    char getMatrix(int i, int j) const { return map.getMatrix(i, j); }

    int getMonsters() const { return monsters; }

    int getTreasures() const { return treasures; }

    Stack* getPaths() const { return map.generatePaths(); }

    void print() const;

};

#endif // !__MAP_HPP
