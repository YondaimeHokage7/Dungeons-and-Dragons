#ifndef __INVENTORY_HPP
#define __INVENTORY_HPP

#include "item.hpp"
#include "functions.hpp"

/// An inventory class
class Inventory
{
private:
    /// An array of three items
    Item items[3];
    // !!!
    bool hasWeapon;
    bool hasSpell;
    bool hasArmor;
    // !!!
public:
    /// Default constructor
    Inventory();
    /// Strength modifier getter
    int getStrengthModifier() const { return items[0].getModifier(); }
    /// Mana modifier getter
    int getSpellModifier() const { return items[1].getModifier(); }
    /// Armor modifier getter
    int getArmorModifier() const { return items[2].getModifier(); }
    /// Item getter
    const Item& getItems(int i) const { return items[i]; }
    /// Weapon setter
    void setWeapon(const Item& weapon);
    /// Spell setter
    void setSpell(const Item& spell);
    /// Armor setter
    void setArmor(const Item& armor);

    // moje bi shte go promenq
    bool weaponCheck() { return hasWeapon; }
    bool spellCheck() { return hasSpell; }
    bool armorCheck() { return hasArmor; }

    /// A function that adds an item to the invetory
    void add(const Item& item);
    /// A function that prints the inventory
    void print(std::ostream& os = std::cout) const;
    /// A function that adds an armor to the invetory
    void addArmor(const Item& armor);
    /// A function that adds a spell to the invetory
    void addSpell(const Item& spell);
    /// A function that adds a weapon to the invetory
    void addWeapon(const Item& weapon);
    /// Overloaded >> operator
    friend std::istream& operator>>(std::istream& is, Inventory& inventory);

};

/// Overloaded << operator
std::ostream& operator << (std::ostream& os, const Inventory& inventory);

#endif // !__INVENTORY_HPP


