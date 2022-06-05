#ifndef __MAP_HPP
#define __MAP_HPP

#include <string>
#include "matrix.hpp"

const std::string level1Name = "level1.txt";
const std::string level2Name = "level2.txt";
const std::string prefix = "level";
const std::string suffix = ".txt";

class Map : public Matrix
{
private:
    int level;

    int monsters, treasures;
    
    void generateNextFile() const;
    
    void printBorder() const;

public:
    Map(int level = 0);

    int getLevel() const { return level; }

    int getMonsters() const { return monsters; }

    int getTreasures() const { return treasures; }
    
    int getFileStat(std::string stat, int _level) const;

    void print() const;

    void addTreasures();

    void addMonsters();

    void levelUp();
};
#endif // !__MAP_HPP
