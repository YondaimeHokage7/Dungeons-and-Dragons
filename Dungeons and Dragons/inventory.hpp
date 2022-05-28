#ifndef __INVENTORY_HPP
#define __INVENTORY_HPP

#include "item.hpp"
#include "armor.hpp"
#include "weapon.hpp"
#include "spell.hpp"

class Inventory
{
private:
    Item items[3];
    /*
    bool hasWeapon;
    bool hasSpell;
    bool hasArmor;
    */
public:
    Inventory();
    int getStrengthModifier() const { return items[0].getModifier(); }
    int getSpellModifier() const { return items[1].getModifier(); }
    int getArmorModifier() const { return items[2].getModifier(); }

    void print() const;
    //void addArmor();
};


#endif // !__INVENTORY_HPP


