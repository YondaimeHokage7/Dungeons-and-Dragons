#ifndef __SPELL_HPP
#define __SPELL_HPP

#include "item.hpp"

class Spell : public Item
{
public:
    Spell(std::string _name = "Awkward old potion", int _modifier = 0);
};

#endif // !__SPELL_HPP


