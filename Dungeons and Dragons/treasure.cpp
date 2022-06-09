#include <sstream>
#include <fstream>
#include "treasure.hpp"


Treasure::Treasure(const Map& map)
{
    std::stringstream fileNameStream;
    fileNameStream << treasureFile << map.getLevel() << suffix;
    std::string fileName = fileNameStream.str();
    std::ifstream stats(fileName, std::ios::in);
    int itemNum{randomBetween(0, 8)};
    int counter{0};
    while (stats.good() && counter <= itemNum)
    {
        Item fileItem;
        stats >> fileItem;
        counter++;
        item = fileItem;
    }
    std::stringstream newName;
    newName << treasure << map.getLevel() + 1 << extenstion;
    std::string nextFile = newName.str();
    std::ifstream next(nextFile, std::ios::in);
    if (!next.is_open())
    {
        generateNext(map.getLevel());
    }

}

void Treasure::generateNext(int level)
{
    std::stringstream fileNameStream;
    std::stringstream oldNameStream;
    oldNameStream << treasure << level << extenstion;
    fileNameStream << treasure << level + 1 << extenstion;
    std::string newFileName = fileNameStream.str();
    std::string oldFileName = oldNameStream.str();
    std::ofstream nextLevel(newFileName, std::ios::out);
    std::ifstream previousLevel(oldFileName, std::ios::in);
    Item defaultItem("A completely useless item", "");
    while (previousLevel.good())
    {
        Item placeholder;
        previousLevel >> placeholder;
        if (placeholder != defaultItem)
        {
            placeholder.setModifier(placeholder.getModifier() + 0.5 + (double)15 / 100 * placeholder.getModifier()); //Increase item modifier by 15%
            nextLevel << placeholder;
        }
    }
}

std::istream& operator>>(std::istream& is, Treasure& treasure)
{
    return is >> treasure.item;
}

std::ostream& operator << (std::ostream& os, const Treasure& trearsure)
{
    return os << trearsure.getItem().getType() << '\n' << trearsure.getItem().getName() << '\n' << trearsure.getItem().getModifier() << '\n';
}