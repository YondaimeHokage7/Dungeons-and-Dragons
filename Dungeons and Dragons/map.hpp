#ifndef __MAP_HPP
#define __MAP_HPP

#include <string>

const std::string level1Name = "level1.txt";
const std::string level2Name = "level2.txt";


class Map
{
private:
    //----------------Level 1----------------//
    //static const int level1Height{10};
    //static const int level1Width{10};
    //static const int level1Monsters{2};
    //static const int level1Treasures{2};
    //----------------Level 2----------------//
    //static const int level2Height{15};
    //static const int level2Width{10};
    //static const int level2Monsters{3};
    //static const int level2Treasures{2};
    //---------------------------------------//
    int level;
    int height, width, monsters, treasures;
    char** map;
public:
    Map(int level = 0/*, int _height = 0, int _width = 0, int _monsters = 0, int _treasures = 0*/);

    Map(const Map&);

    Map& operator=(const Map&);

    ~Map();

    int getLevel() const { return level; }
    int getHeight() const { return height; }
    int getWidth() const { return width; }
    int getMonsters() const { return monsters; }
    int getTreasures() const { return treasures; }

    void generateNextFile() const;
};

#endif // !__MAP_HPP
