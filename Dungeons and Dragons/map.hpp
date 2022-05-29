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
public:
    Map(int level = 0);

    int getLevel() const { return level; }

    int getHeight() const { return map.getColumns(); }

    int getWidth() const { return map.getRows(); }

    int getMonsters() const { return monsters; }

    int getTreasures() const { return treasures; }
};

#endif // !__MAP_HPP
