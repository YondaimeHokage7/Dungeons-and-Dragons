#include "item.hpp"
#include <string>

Item::Item(std::string _name, std::string _type, int _modifier) : name(_name), type(_type), modifier(_modifier)
{}

std::istream& operator>>(std::istream& is, Item& item)
{
    std::getline(is, item.type);
    std::getline(is, item.name);
    is >> item.modifier;
    return is;
}

std::ostream& operator <<(std::ostream& os, const Item& item)
{
    return os << item.getType() << '\n' << item.getName() << '\n' << item.getModifier() << '\n';
}