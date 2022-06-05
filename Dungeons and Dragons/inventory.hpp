#ifndef __INVENTORY_HPP
#define __INVENTORY_HPP

#include "item.hpp"
#include "functions.hpp"

class Inventory
{
private:
    Item items[3];
    bool hasWeapon;
    bool hasSpell;
    bool hasArmor;
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

    void setWeapon(const Item& weapon);
    void setSpell(const Item& spell);
    void setArmor(const Item& armor);

    bool weaponCheck() { return hasWeapon; }
    bool spellCheck() { return hasSpell; }
    bool armorCheck() { return hasArmor; }

    //void add(const Item& item);

    void print() const;
    //void addArmor();
};


#endif // !__INVENTORY_HPP


