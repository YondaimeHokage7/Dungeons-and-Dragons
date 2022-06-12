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
    static int remainingMonsters;

    static int remainingTreasures;

    Map(int level = 1);

    Map(int _level, int _monsters, int _treasures, int _rows, int _columns, int _numberOfConnections, CellIndex* _connections, int remainingMonsters, int remainingTreasures);

    int getLevel() const { return level; }

    int getMonsters() const { return monsters; }

    int getTreasures() const { return treasures; }

    int getFileStat(std::string stat, int _level) const;

    void print() const;

    void addTreasures();

    void addMonsters();

    void levelUp();

    CellIndex* getMonsterPostitions() const;

    CellIndex* getTreasurePostitions() const;

    friend std::istream& operator>>(std::istream& is, Map& map);

};

std::ostream& operator<<(std::ostream& os, const Map& map);


#endif // !__MAP_HPP
