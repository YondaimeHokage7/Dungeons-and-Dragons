#ifndef __WEAPON_HPP
#define __WEAPON_HPP

#include <string>
#include "item.hpp"

/// A class representing an item of type Weapon
class Weapon : public Item
{
public:
    /// Default parameter constructor
    Weapon(std::string _name = "Rusty old sword", int _modifier = 0);
};

#endif // !__WEAPON_HPP

