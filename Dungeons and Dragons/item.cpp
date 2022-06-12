#include "item.hpp"
#include <string>

Item::Item(std::string _name, std::string _type, int _modifier) : name(_name), type(_type), modifier(_modifier)
{}

std::istream& operator>>(std::istream& is, Item& item)
{
    std::getline(is, item.type,'\n');
    std::getline(is, item.name,'\n');
    is >> item.modifier;
    is.ignore();
    return is;
}

std::ostream& operator <<(std::ostream& os, const Item& item)
{
    if(&os == &std::cout)
    {
        return os << "Type: " << item.getType() << '\n' << "Name: " << item.getName() << '\n' << "Modifier: " << item.getModifier() << '\n';
    }
    else
    {
        return os << item.getType() << '\n' << item.getName() << '\n' << item.getModifier() << '\n';
    }
}

bool operator!=(Item& item1, Item& item2)
{
    return item1.getType() != item2.getType() || item1.getName() != item2.getName() || item1.getModifier() != item2.getModifier();
}