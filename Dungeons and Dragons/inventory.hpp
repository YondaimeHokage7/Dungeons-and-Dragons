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

    /// Keeps track of what types of items the player has in the inventory
    bool hasWeapon;

    /// Keeps track of what types of items the player has in the inventory
    bool hasSpell;

    /// Keeps track of what types of items the player has in the inventory
    bool hasArmor;

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

    /// Checks if the player has a weapon
    bool weaponCheck() { return hasWeapon; }

    /// Checks if the player has a spell
    bool spellCheck() { return hasSpell; }

    /// Checks if the player has an armor
    bool armorCheck() { return hasArmor; }

    /// A function that adds an item to the inventory
    void add(const Item& item);

    /// A function that prints the inventory
    void print(std::ostream& os = std::cout) const;

    /// A function that adds an armor to the inventory
    void addArmor(const Item& armor);

    /// A function that adds a spell to the inventory
    void addSpell(const Item& spell);

    /// A function that adds a weapon to the inventory
    void addWeapon(const Item& weapon);

    /// Overloaded >> operator
    friend std::istream& operator>>(std::istream& is, Inventory& inventory);

};

/// Overloaded << operator
std::ostream& operator << (std::ostream& os, const Inventory& inventory);

#endif // !__INVENTORY_HPP


