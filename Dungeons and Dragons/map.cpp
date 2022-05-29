#include "map.hpp"
#include <fstream>
#include <iostream>
#include <sstream>


Map::Map(int _level/*, int _height, int _width, int _monsters, int _treasures*/) : level(_level)/*, height(_height), width(_width), monsters(_monsters), treasures(_treasures),*/
{
    map = nullptr;
    std::stringstream levelFileStream;
    levelFileStream << "level" << level << ".txt";
    std::string fileName = levelFileStream.str();
    std::ifstream levelFile(fileName,std::ios::in);
    levelFile >> height >> width >> monsters >> treasures;

    delete[] map;
    map = new char* [height]{};
    for (int i{0}; i < height; i++)
    {
        map[i] = new char[width]{};
    }
}

Map::Map(const Map& other) : level(other.level), height(other.height), width(other.width), monsters(other.monsters), treasures(other.treasures), map(nullptr)
{
    delete[] map;
    map = new char* [other.height];
    for (int i{0}; i < height; i++)
    {
        map[i] = new char[other.width];
    }
    for (int i{0}; i < height; i++)
    {
        for (int j{0}; j < width; j++)
        {
            map[i][j] = other.map[i][j];
        }
    }
}

Map& Map::operator=(const Map& other)
{
    if (this != &other)
    {
        level = other.level;
        height = other.height;
        width = other.width;
        monsters = other.monsters;
        treasures = other.treasures;
        delete[] map;
        map = new char* [other.height];
        for (int i{0}; i < height; i++)
        {
            map[i] = new char[other.width];
        }
        for (int i{0}; i < height; i++)
        {
            for (int j{0}; j < width; j++)
            {
                map[i][j] = other.map[i][j];
            }
        }
    }
    return *this;
}

Map::~Map()
{
    for (int i{0}; i < height; i++)
    {
        delete[] map[i];
    }
    delete[] map;
}

/*
int generateFile(int level)
{
    if (level <= 2)
    {
        int height1, width1, monsters1, treasures1;
        std::ifstream level1File(level1Name, std::ios::in);
        level1File >> height1 >> width1 >> monsters1 >> treasures1;
        level1File.close();
        int height2, width2, monsters2, treasures2;
        std::ifstream level2File(level2Name, std::ios::in);
        level2File >> height2 >> width2 >> monsters2 >> treasures2;
        level2File.close();
        return level;
    }
    else
    {
        std::stringstream constrcutName;
        constrcutName << "level" << level << ".txt";
        std::string newFileName;
        newFileName = constrcutName.str();
        std::ofstream(newFileName, std::ios::app);

    }
}
*/

void Map::generateNextFile() const
{
    if (this->getLevel() >= 2)
    {
        int current[5]{getLevel(), getHeight(), getWidth(), getMonsters(), getTreasures()};
        int previous[5]{getLevel() - 1};
        std::stringstream currentNameStream;
        std::stringstream previousNameStream;
        std::stringstream nextNameStream;
        nextNameStream << "level" << current[0] + 1 << ".txt";
        currentNameStream << "level" << current[0] << ".txt";
        previousNameStream << "level" << current[0] - 1 << ".txt";
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
}
