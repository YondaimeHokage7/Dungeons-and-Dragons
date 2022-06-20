#ifndef __SPELL_HPP
#define __SPELL_HPP

#include "item.hpp"

/// A class representing an item of type Spell
class Spell : public Item
{
public:
    /// Default parameter constructor
    Spell(std::string _name = "Awkward old potion", int _modifier = 0);
};

#endif // !__SPELL_HPP


