#ifndef __MAP_HPP
#define __MAP_HPP

#include <string>
#include "matrix.hpp"

/// Default level 1 file name
const std::string level1Name = "level1.txt";
/// Default level 2 file name
const std::string level2Name = "level2.txt";
/// Default file prefix
const std::string prefix = "level";
/// Default file suffix
const std::string suffix = ".txt";

/// A class representing the map
class Map : public Matrix
{
private:
    /// The current map level
    int level;
    /// Nnumber of fmonsters
    int monsters;
    /// Number of treasures
    int treasures;
    /// A private function generating the next level stats
    void generateNextFile() const;
    /// A function printing the header and the footer of the map
    void printBorder() const;
public:
    /// Number of monsters that have not been defeated
    static int remainingMonsters;
    /// Number of monsters that have not been looted
    static int remainingTreasures;
    /// Default parameter constructor
    Map(int level = 1);
    /// Parameter constructor
    Map(int _level, int _monsters, int _treasures, int _rows, int _columns, int _numberOfConnections, CellIndex* _connections, int remainingMonsters, int remainingTreasures);
    /// Map level getter
    int getLevel() const { return level; }
    /// Map monsters getter
    int getMonsters() const { return monsters; }
    /// Map treasures getter
    int getTreasures() const { return treasures; }
    ///
    int getFileStat(std::string stat, int _level) const;
    /// A function printing the map
    void print() const;
    /// A function that places treasures on the map
    void addTreasures();
    /// A function that places monsters on the map
    void addMonsters();
    /// A function that increases the level of the map
    void levelUp();
    /// A function returning the positions of the monsters
    CellIndex* getMonsterPostitions() const;
    /// A function returning the positions of the treasures
    CellIndex* getTreasurePostitions() const;
    /// Overloaded operator >>
    friend std::istream& operator>>(std::istream& is, Map& map);

};
/// Overloaded operator <<
std::ostream& operator<<(std::ostream& os, const Map& map);


#endif // !__MAP_HPP
