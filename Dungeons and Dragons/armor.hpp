#ifndef __ARMOR_HPP
#define __ARMOR_HPP

#include "item.hpp"

/// A class representing an item of type Armor
class Armor : public Item
{
public:
    /// Default parameter constructor
    Armor(std::string _name = "Flimsy old tunic", int _modifier = 0);
};

#endif // !__ARMOR_HPP
