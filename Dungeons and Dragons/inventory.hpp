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
    const Item& getItems(int i) const { return items[i]; }

    void setWeapon(const Item& weapon);
    void setSpell(const Item& spell);
    void setArmor(const Item& armor);

    bool weaponCheck() { return hasWeapon; }
    bool spellCheck() { return hasSpell; }
    bool armorCheck() { return hasArmor; }

    void add(const Item& item);

    void print(std::ostream& os = std::cout) const;
    void addArmor(const Item& armor);
    void addSpell(const Item& spell);
    void addWeapon(const Item& weapon);

    friend std::istream& operator>>(std::istream& is, Inventory& inventory);

};

std::ostream& operator << (std::ostream& os, const Inventory& inventory);

#endif // !__INVENTORY_HPP


