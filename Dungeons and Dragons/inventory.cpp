#include <iostream>
#include "inventory.hpp"
#include "weapon.hpp"
#include "spell.hpp"

Inventory::Inventory() : hasWeapon(true), hasSpell(true), hasArmor(false)
{
    items[0] = Weapon("An ordinary sword", 20);
    items[1] = Spell("Fireball", 20);
    items[2] = Item();
}

void Inventory::print() const
{
    for (int i{0}; i < 3; i++)
    {
        std::cout << items[i].getName() << '\n';
    }
}

void Inventory::setWeapon(const Item& weapon)
{
    if (!hasWeapon)
    {
        items[0] = weapon;
    }
    else
    {
        char answer[4];
        std::cout << "Already have a weapon!\n";
        std::cout << "Would you like to replace it?";
        std::cin.getline(answer, 4, '\n');
        if (myStrcmp(answer, "Yes"))
        {
            items[0] = weapon;
        }
    }
    hasWeapon = true;
}

void Inventory::setSpell(const Item& spell)
{
    if (!hasSpell)
    {
        items[0] = spell;
    }
    else
    {
        char answer[4];
        std::cout << "Already have a spell!\n";
        std::cout << "Would you like to replace it?";
        std::cin.getline(answer, 4, '\n');
        if (myStrcmp(answer, "Yes"))
        {
            items[0] = spell;
        }
    }
    hasSpell = true;
}

void Inventory::setArmor(const Item& armor)
{
    if (!hasArmor)
    {
        items[0] = armor;
    }
    else
    {
        char answer[4];
        std::cout << "Already have an armor!\n";
        std::cout << "Would you like to replace it?";
        std::cin.getline(answer, 4, '\n');
        if (myStrcmp(answer, "Yes"))
        {
            items[0] = armor;
        }
    }
    hasArmor = true;
}

//void Inventory::add(const Item& item)
//{

//}

/*
void Inventory::addArmor()
{
    char answer[3];
    if (hasArmor)
    {
        std::cout << "You already have an armor in your inventory!\n";
        std::cout << "Would you like to replace " << items[2].getName() << "with --TREASURE--";
        std::cin >> answer;
        if (answer == "yes")
        {
            //
        }
    }
}
*/