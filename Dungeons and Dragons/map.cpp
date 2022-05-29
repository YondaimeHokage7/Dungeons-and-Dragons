#include "map.hpp"
#include <fstream>
#include <iostream>
#include <sstream>


Map::Map(int _level) : level(_level)
{
    std::stringstream levelFileStream;
    levelFileStream << prefix << level << suffix;
    std::string fileName = levelFileStream.str();
    std::ifstream levelFile(fileName,std::ios::in);
    int height, width;
    levelFile >> height >> width >> monsters >> treasures;
    map = Matrix(height, width);
    if (level >= 2)
    {
        generateNextFile();
    }
}

void Map::generateNextFile() const
{
    if (getLevel() >= 2)
    {
        int current[5]{getLevel(), getHeight(), getWidth(), getMonsters(), getTreasures()};
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
}
