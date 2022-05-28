#ifndef __WEAPON_HPP
#define __WEAPON_HPP

#include <string>
#include "item.hpp"

class Weapon : public Item
{
public:
    Weapon(std::string _name = "Rusty old sword", int _modifier = 0);
};

#endif // !__WEAPON_HPP

