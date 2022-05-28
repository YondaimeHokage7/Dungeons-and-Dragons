#ifndef __ARMOR_HPP
#define __ARMOR_HPP

#include "item.hpp"

class Armor : public Item
{
public:
    Armor(std::string _name = "Flimsy old tunic", int _modifier = 0);
};

#endif // !__ARMOR_HPP
