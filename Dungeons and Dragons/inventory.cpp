#include <iostream>
#include "inventory.hpp"
#include "weapon.hpp"
#include "spell.hpp"
#include "armor.hpp"

Inventory::Inventory() : hasWeapon(true), hasSpell(true), hasArmor(false)
{
    items[0] = Weapon("An ordinary sword", 20);
    items[1] = Spell("Fireball", 20);
    items[2] = Armor("n/a", 0);
}

void Inventory::print(std::ostream& os) const
{
    if (&os == &std::cout)
    {
        for (int i{0}; i < 3; i++)
        {
            os << items[i].getType() << " : " << items[i].getName() << ' ' << items[i].getModifier() << '\n';
        }
    }
    else
    {
        for (int i{0}; i < 3; i++)
        {
            os << items[i].getName() << ' ' << items[i].getModifier() << '\n';
        }
    }
}

void Inventory::setWeapon(const Item& weapon)
{
    items[0] = weapon;
    hasWeapon = true;
}

void Inventory::setSpell(const Item& spell)
{
    items[1] = spell;
    hasSpell = true;
}

void Inventory::setArmor(const Item& armor)
{
    items[2] = armor;
    hasArmor = true;
}

void Inventory::add(const Item& item)
{
    if (item.getType() == "Armor")
    {
        addArmor(item);
    }
    else if (item.getType() == "Weapon")
    {
        addWeapon(item);
    }
    else if (item.getType() == "Spell")
    {
        addSpell(item);
    }
}

void Inventory::addArmor(const Item& armor)
{
    if (hasArmor)
    {
        char answer[4];
        std::cout << "You already have an armor in your inventory!\n";
        std::cout << "Would you like to replace " << items[2].getName() << " with " << armor.getName() << '\n';
        std::cin.getline(answer, 4, '\n');
        if (myStrcmp(answer, "Yes"))
        {
            std::cout << armor.getName() << " is now equipped!\n";
            setArmor(armor);
        }
        else if (myStrcmp(answer, "No"))
        {
            std::cout << armor.getName() << " was destroyed!\n";
        }
    }
    else
    {
        std::cout << armor.getName() << " is now equipped!\n";
        setArmor(armor);
    }
}

void Inventory::addSpell(const Item& spell)
{
    if (hasSpell)
    {
        char answer[4];
        std::cout << "You already have a spell in your inventory!\n";
        std::cout << "Would you like to replace " << items[1].getName() << " with " << spell.getName() << '\n';
        std::cin.getline(answer, 4, '\n');
        if (myStrcmp(answer, "Yes"))
        {
            std::cout << spell.getName() << " is now equipped!\n";
            setSpell(spell);
        }
        else if (myStrcmp(answer, "No"))
        {
            std::cout << spell.getName() << " was destroyed!\n";
        }
    }
    else
    {
        std::cout << spell.getName() << " is now equipped!\n";
        setSpell(spell);
    }
}

void Inventory::addWeapon(const Item& weapon)
{
    if (hasWeapon)
    {
        char answer[4];
        std::cout << "You already have a weapon in your inventory!\n";
        std::cout << "Would you like to replace " << items[0].getName() << " with " << weapon.getName() << '\n';
        std::cin.getline(answer, 4, '\n');
        if (myStrcmp(answer, "Yes"))
        {
            std::cout << weapon.getName() << " is now equipped!\n";
            setWeapon(weapon);
        }
        else if (myStrcmp(answer, "No"))
        {
            std::cout << weapon.getName() << " was destroyed!\n";
        }
    }
    else
    {
        std::cout << weapon.getName() << " is now equipped!\n";
        setWeapon(weapon);
    }
}

std::istream& operator>>(std::istream& is, Inventory& inventory)
{
    is.ignore();
    for (int i{0}; i < 3; i++)
    {
        is >> inventory.items[i];
    }
    return is;
}

std::ostream& operator << (std::ostream& os, const Inventory& inventory)
{
    for (int i{0}; i < 3; i++)
    {
        os << inventory.getItems(i);
    }
    return os;
}